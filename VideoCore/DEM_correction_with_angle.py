import rasterio
import numpy as np
from rasterio.transform import from_origin
from math import tan, radians


def dem_correction(tiff_rgbir_path, tiff_dem_path, lon_angle, lat_angle, output_path):
    with rasterio.open(tiff_rgbir_path) as src_rgbir, rasterio.open(tiff_dem_path) as src_dem:
        rgbir_image = src_rgbir.read()
        dem_image = src_dem.read(1)

        transform_rgbir = src_rgbir.transform
        meta = src_rgbir.meta

        lon_angle_rad = radians(lon_angle)
        lat_angle_rad = radians(lat_angle)

        height, width = dem_image.shape
        pixel_coords = np.indices((height, width))
        x_coords = pixel_coords[1]
        y_coords = pixel_coords[0]

        # Lấy giá trị độ cao (hxy) cho mỗi điểm ảnh từ DEM
        hxy = dem_image

        x_new = x_coords + hxy * np.tan(lon_angle_rad)
        y_new = y_coords + hxy * np.tan(lat_angle_rad)

        adjusted_image = np.zeros_like(rgbir_image)
        for i in range(4):
            for y in range(height):
                for x in range(width):
                    new_x = int(x_new[y, x])
                    new_y = int(y_new[y, x])
                    if 0 <= new_x < width and 0 <= new_y < height:
                        adjusted_image[i, new_y, new_x] = rgbir_image[i, y, x]

        meta.update({
            'driver': 'GTiff',
            'height': adjusted_image.shape[1],
            'width': adjusted_image.shape[2],
            'transform': from_origin(transform_rgbir[2], transform_rgbir[5], transform_rgbir[0], transform_rgbir[4])
        })

        with rasterio.open(output_path, 'w', **meta) as dst:
            dst.write(adjusted_image)



dem_correction(
    tiff_rgbir_path="quang_ninh_1m.tif",
    tiff_dem_path="dem_haiphong_quangninh.tif",
    lon_angle=15,
    lat_angle=10,
    output_path="output.tif"
)



