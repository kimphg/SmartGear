import numpy as np
import rasterio
from rasterio.warp import reproject
from rasterio.enums import Resampling
from rasterio.plot import show
with rasterio.open('DEM_input.tif') as source:
    print("rpcs:")
    print(source.rpcs)
    src_crs = source.crs#"EPSG:4326"  # This is the crs of the rpcs

    kwargs = {
        'RPC_DEM': 'nui_qn_dem.tif'
    }
    
    # pyplot.show()
    # Destination: a 1024 x 1024 dataset in Web Mercator (EPSG:3857)
    
    dst_crs = "EPSG:3857"
    destination_red = np.zeros((1024, 1024), dtype=np.uint8)
    _, dst_transform = reproject(
        rasterio.band(source, 1),
        destination_red,
        rpcs=source.rpcs,
        src_crs=src_crs,
        dst_crs=dst_crs,
        resampling=Resampling.nearest,
        **kwargs
    )
    destination_g = np.zeros((1024, 1024), dtype=np.uint8)
    _, dst_transform = reproject(
        rasterio.band(source, 2),
        destination_g,
        rpcs=source.rpcs,
        src_crs=src_crs,
        dst_crs=dst_crs,
        resampling=Resampling.nearest,
        **kwargs
    )
    destination_b= np.zeros((1024, 1024), dtype=np.uint8)
    _, dst_transform = reproject(
        rasterio.band(source, 3),
        destination_b,
        rpcs=source.rpcs,
        src_crs=src_crs,
        dst_crs=dst_crs,
        resampling=Resampling.nearest,
        **kwargs
    )
    profile = source.profile
    profile.update(
        dtype=rasterio.uint8,
        count=3)
    # show(destination, transform=dst_transform)
    with rasterio.open('dem_output.tif', 'w', **profile) as dst:
        dst.write(destination_red.astype(rasterio.uint8), 1)
        dst.write(destination_g.astype(rasterio.uint8), 2)
        dst.write(destination_b.astype(rasterio.uint8), 3)
    assert destination_red.any()