#pragma once

#include "phpx.h"
#include "phpx_literal_string.h"
#include "phpx_class.h"

namespace php {

Variant gd_info();
GdFont imageloadfont(const Variant &filename);
Variant imagesetstyle(const GdImage &image, const Variant &style);
Variant imagesetstyle(const Variant &image, const Variant &style);
GdImage imagecreatetruecolor(const Variant &width, const Variant &height);
Variant imageistruecolor(const GdImage &image);
Variant imageistruecolor(const Variant &image);
Variant imagetruecolortopalette(const GdImage &image, const Variant &dither, const Variant &num_colors);
Variant imagetruecolortopalette(const Variant &image, const Variant &dither, const Variant &num_colors);
Variant imagepalettetotruecolor(const GdImage &image);
Variant imagepalettetotruecolor(const Variant &image);
Variant imagecolormatch(const GdImage &image1, const GdImage &image2);
Variant imagecolormatch(const Variant &image1, const Variant &image2);
Variant imagesetthickness(const GdImage &image, const Variant &thickness);
Variant imagesetthickness(const Variant &image, const Variant &thickness);
Variant imagefilledellipse(const GdImage &image,
                           const Variant &center_x,
                           const Variant &center_y,
                           const Variant &width,
                           const Variant &height,
                           const Variant &color);
Variant imagefilledellipse(const Variant &image,
                           const Variant &center_x,
                           const Variant &center_y,
                           const Variant &width,
                           const Variant &height,
                           const Variant &color);
Variant imagefilledarc(const GdImage &image,
                       const Variant &center_x,
                       const Variant &center_y,
                       const Variant &width,
                       const Variant &height,
                       const Variant &start_angle,
                       const Variant &end_angle,
                       const Variant &color,
                       const Variant &style);
Variant imagefilledarc(const Variant &image,
                       const Variant &center_x,
                       const Variant &center_y,
                       const Variant &width,
                       const Variant &height,
                       const Variant &start_angle,
                       const Variant &end_angle,
                       const Variant &color,
                       const Variant &style);
Variant imagealphablending(const GdImage &image, const Variant &enable);
Variant imagealphablending(const Variant &image, const Variant &enable);
Variant imagesavealpha(const GdImage &image, const Variant &enable);
Variant imagesavealpha(const Variant &image, const Variant &enable);
Variant imagelayereffect(const GdImage &image, const Variant &effect);
Variant imagelayereffect(const Variant &image, const Variant &effect);
Variant imagecolorallocatealpha(
    const GdImage &image, const Variant &red, const Variant &green, const Variant &blue, const Variant &alpha);
Variant imagecolorallocatealpha(
    const Variant &image, const Variant &red, const Variant &green, const Variant &blue, const Variant &alpha);
Variant imagecolorresolvealpha(
    const GdImage &image, const Variant &red, const Variant &green, const Variant &blue, const Variant &alpha);
Variant imagecolorresolvealpha(
    const Variant &image, const Variant &red, const Variant &green, const Variant &blue, const Variant &alpha);
Variant imagecolorclosestalpha(
    const GdImage &image, const Variant &red, const Variant &green, const Variant &blue, const Variant &alpha);
Variant imagecolorclosestalpha(
    const Variant &image, const Variant &red, const Variant &green, const Variant &blue, const Variant &alpha);
Variant imagecolorexactalpha(
    const GdImage &image, const Variant &red, const Variant &green, const Variant &blue, const Variant &alpha);
Variant imagecolorexactalpha(
    const Variant &image, const Variant &red, const Variant &green, const Variant &blue, const Variant &alpha);
Variant imagecopyresampled(const GdImage &dst_image,
                           const GdImage &src_image,
                           const Variant &dst_x,
                           const Variant &dst_y,
                           const Variant &src_x,
                           const Variant &src_y,
                           const Variant &dst_width,
                           const Variant &dst_height,
                           const Variant &src_width,
                           const Variant &src_height);
Variant imagecopyresampled(const Variant &dst_image,
                           const Variant &src_image,
                           const Variant &dst_x,
                           const Variant &dst_y,
                           const Variant &src_x,
                           const Variant &src_y,
                           const Variant &dst_width,
                           const Variant &dst_height,
                           const Variant &src_width,
                           const Variant &src_height);
GdImage imagerotate(const GdImage &image, const Variant &angle, const Variant &background_color);
Variant imagerotate(const Variant &image, const Variant &angle, const Variant &background_color);
Variant imagesettile(const GdImage &image, const GdImage &tile);
Variant imagesettile(const Variant &image, const Variant &tile);
Variant imagesetbrush(const GdImage &image, const GdImage &brush);
Variant imagesetbrush(const Variant &image, const Variant &brush);
GdImage imagecreate(const Variant &width, const Variant &height);
Variant imagetypes();
GdImage imagecreatefromstring(const Variant &data);
GdImage imagecreatefromgif(const Variant &filename);
GdImage imagecreatefromjpeg(const Variant &filename);
GdImage imagecreatefrompng(const Variant &filename);
GdImage imagecreatefromwebp(const Variant &filename);
GdImage imagecreatefromxbm(const Variant &filename);
GdImage imagecreatefromwbmp(const Variant &filename);
GdImage imagecreatefromgd(const Variant &filename);
GdImage imagecreatefromgd2(const Variant &filename);
GdImage imagecreatefromgd2part(
    const Variant &filename, const Variant &x, const Variant &y, const Variant &width, const Variant &height);
GdImage imagecreatefrombmp(const Variant &filename);
GdImage imagecreatefromtga(const Variant &filename);
Variant imagexbm(const GdImage &image, const Variant &filename, const Variant &foreground_color = nullptr);
Variant imagexbm(const Variant &image, const Variant &filename, const Variant &foreground_color = nullptr);
Variant imagegif(const GdImage &image, const Variant &file = nullptr);
Variant imagegif(const Variant &image, const Variant &file = nullptr);
Variant imagepng(const GdImage &image,
                 const Variant &file = nullptr,
                 const Variant &quality = -1,
                 const Variant &filters = -1);
Variant imagepng(const Variant &image,
                 const Variant &file = nullptr,
                 const Variant &quality = -1,
                 const Variant &filters = -1);
Variant imagewebp(const GdImage &image, const Variant &file = nullptr, const Variant &quality = -1);
Variant imagewebp(const Variant &image, const Variant &file = nullptr, const Variant &quality = -1);
Variant imagejpeg(const GdImage &image, const Variant &file = nullptr, const Variant &quality = -1);
Variant imagejpeg(const Variant &image, const Variant &file = nullptr, const Variant &quality = -1);
Variant imagewbmp(const GdImage &image, const Variant &file = nullptr, const Variant &foreground_color = nullptr);
Variant imagewbmp(const Variant &image, const Variant &file = nullptr, const Variant &foreground_color = nullptr);
Variant imagegd(const GdImage &image, const Variant &file = nullptr);
Variant imagegd(const Variant &image, const Variant &file = nullptr);
Variant imagegd2(const GdImage &image,
                 const Variant &file = nullptr,
                 const Variant &chunk_size = 128,
                 const Variant &mode = 1);
Variant imagegd2(const Variant &image,
                 const Variant &file = nullptr,
                 const Variant &chunk_size = 128,
                 const Variant &mode = 1);
Variant imagebmp(const GdImage &image, const Variant &file = nullptr, const Variant &compressed = true);
Variant imagebmp(const Variant &image, const Variant &file = nullptr, const Variant &compressed = true);
Variant imagedestroy(const GdImage &image);
Variant imagedestroy(const Variant &image);
Variant imagecolorallocate(const GdImage &image, const Variant &red, const Variant &green, const Variant &blue);
Variant imagecolorallocate(const Variant &image, const Variant &red, const Variant &green, const Variant &blue);
Variant imagepalettecopy(const GdImage &dst, const GdImage &src);
Variant imagepalettecopy(const Variant &dst, const Variant &src);
Variant imagecolorat(const GdImage &image, const Variant &x, const Variant &y);
Variant imagecolorat(const Variant &image, const Variant &x, const Variant &y);
Variant imagecolorclosest(const GdImage &image, const Variant &red, const Variant &green, const Variant &blue);
Variant imagecolorclosest(const Variant &image, const Variant &red, const Variant &green, const Variant &blue);
Variant imagecolorclosesthwb(const GdImage &image, const Variant &red, const Variant &green, const Variant &blue);
Variant imagecolorclosesthwb(const Variant &image, const Variant &red, const Variant &green, const Variant &blue);
Variant imagecolordeallocate(const GdImage &image, const Variant &color);
Variant imagecolordeallocate(const Variant &image, const Variant &color);
Variant imagecolorresolve(const GdImage &image, const Variant &red, const Variant &green, const Variant &blue);
Variant imagecolorresolve(const Variant &image, const Variant &red, const Variant &green, const Variant &blue);
Variant imagecolorexact(const GdImage &image, const Variant &red, const Variant &green, const Variant &blue);
Variant imagecolorexact(const Variant &image, const Variant &red, const Variant &green, const Variant &blue);
Variant imagecolorset(const GdImage &image,
                      const Variant &color,
                      const Variant &red,
                      const Variant &green,
                      const Variant &blue,
                      const Variant &alpha = 0);
Variant imagecolorset(const Variant &image,
                      const Variant &color,
                      const Variant &red,
                      const Variant &green,
                      const Variant &blue,
                      const Variant &alpha = 0);
Variant imagecolorsforindex(const GdImage &image, const Variant &color);
Variant imagecolorsforindex(const Variant &image, const Variant &color);
Variant imagegammacorrect(const GdImage &image, const Variant &input_gamma, const Variant &output_gamma);
Variant imagegammacorrect(const Variant &image, const Variant &input_gamma, const Variant &output_gamma);
Variant imagesetpixel(const GdImage &image, const Variant &x, const Variant &y, const Variant &color);
Variant imagesetpixel(const Variant &image, const Variant &x, const Variant &y, const Variant &color);
Variant imageline(const GdImage &image,
                  const Variant &x1,
                  const Variant &y1,
                  const Variant &x2,
                  const Variant &y2,
                  const Variant &color);
Variant imageline(const Variant &image,
                  const Variant &x1,
                  const Variant &y1,
                  const Variant &x2,
                  const Variant &y2,
                  const Variant &color);
Variant imagedashedline(const GdImage &image,
                        const Variant &x1,
                        const Variant &y1,
                        const Variant &x2,
                        const Variant &y2,
                        const Variant &color);
Variant imagedashedline(const Variant &image,
                        const Variant &x1,
                        const Variant &y1,
                        const Variant &x2,
                        const Variant &y2,
                        const Variant &color);
Variant imagerectangle(const GdImage &image,
                       const Variant &x1,
                       const Variant &y1,
                       const Variant &x2,
                       const Variant &y2,
                       const Variant &color);
Variant imagerectangle(const Variant &image,
                       const Variant &x1,
                       const Variant &y1,
                       const Variant &x2,
                       const Variant &y2,
                       const Variant &color);
Variant imagefilledrectangle(const GdImage &image,
                             const Variant &x1,
                             const Variant &y1,
                             const Variant &x2,
                             const Variant &y2,
                             const Variant &color);
Variant imagefilledrectangle(const Variant &image,
                             const Variant &x1,
                             const Variant &y1,
                             const Variant &x2,
                             const Variant &y2,
                             const Variant &color);
Variant imagearc(const GdImage &image,
                 const Variant &center_x,
                 const Variant &center_y,
                 const Variant &width,
                 const Variant &height,
                 const Variant &start_angle,
                 const Variant &end_angle,
                 const Variant &color);
Variant imagearc(const Variant &image,
                 const Variant &center_x,
                 const Variant &center_y,
                 const Variant &width,
                 const Variant &height,
                 const Variant &start_angle,
                 const Variant &end_angle,
                 const Variant &color);
Variant imageellipse(const GdImage &image,
                     const Variant &center_x,
                     const Variant &center_y,
                     const Variant &width,
                     const Variant &height,
                     const Variant &color);
Variant imageellipse(const Variant &image,
                     const Variant &center_x,
                     const Variant &center_y,
                     const Variant &width,
                     const Variant &height,
                     const Variant &color);
Variant imagefilltoborder(
    const GdImage &image, const Variant &x, const Variant &y, const Variant &border_color, const Variant &color);
Variant imagefilltoborder(
    const Variant &image, const Variant &x, const Variant &y, const Variant &border_color, const Variant &color);
Variant imagefill(const GdImage &image, const Variant &x, const Variant &y, const Variant &color);
Variant imagefill(const Variant &image, const Variant &x, const Variant &y, const Variant &color);
Variant imagecolorstotal(const GdImage &image);
Variant imagecolorstotal(const Variant &image);
Variant imagecolortransparent(const GdImage &image, const Variant &color = nullptr);
Variant imagecolortransparent(const Variant &image, const Variant &color = nullptr);
Variant imageinterlace(const GdImage &image, const Variant &enable = nullptr);
Variant imageinterlace(const Variant &image, const Variant &enable = nullptr);
Variant imagepolygon(const GdImage &image,
                     const Variant &points,
                     const Variant &num_points_or_color,
                     const Variant &color = nullptr);
Variant imagepolygon(const Variant &image,
                     const Variant &points,
                     const Variant &num_points_or_color,
                     const Variant &color = nullptr);
Variant imageopenpolygon(const GdImage &image,
                         const Variant &points,
                         const Variant &num_points_or_color,
                         const Variant &color = nullptr);
Variant imageopenpolygon(const Variant &image,
                         const Variant &points,
                         const Variant &num_points_or_color,
                         const Variant &color = nullptr);
Variant imagefilledpolygon(const GdImage &image,
                           const Variant &points,
                           const Variant &num_points_or_color,
                           const Variant &color = nullptr);
Variant imagefilledpolygon(const Variant &image,
                           const Variant &points,
                           const Variant &num_points_or_color,
                           const Variant &color = nullptr);
Variant imagefontwidth(const Variant &font);
Variant imagefontheight(const Variant &font);
Variant imagechar(const GdImage &image,
                  const Variant &font,
                  const Variant &x,
                  const Variant &y,
                  const Variant &char_,
                  const Variant &color);
Variant imagechar(const Variant &image,
                  const Variant &font,
                  const Variant &x,
                  const Variant &y,
                  const Variant &char_,
                  const Variant &color);
Variant imagecharup(const GdImage &image,
                    const Variant &font,
                    const Variant &x,
                    const Variant &y,
                    const Variant &char_,
                    const Variant &color);
Variant imagecharup(const Variant &image,
                    const Variant &font,
                    const Variant &x,
                    const Variant &y,
                    const Variant &char_,
                    const Variant &color);
Variant imagestring(const GdImage &image,
                    const Variant &font,
                    const Variant &x,
                    const Variant &y,
                    const Variant &string,
                    const Variant &color);
Variant imagestring(const Variant &image,
                    const Variant &font,
                    const Variant &x,
                    const Variant &y,
                    const Variant &string,
                    const Variant &color);
Variant imagestringup(const GdImage &image,
                      const Variant &font,
                      const Variant &x,
                      const Variant &y,
                      const Variant &string,
                      const Variant &color);
Variant imagestringup(const Variant &image,
                      const Variant &font,
                      const Variant &x,
                      const Variant &y,
                      const Variant &string,
                      const Variant &color);
Variant imagecopy(const GdImage &dst_image,
                  const GdImage &src_image,
                  const Variant &dst_x,
                  const Variant &dst_y,
                  const Variant &src_x,
                  const Variant &src_y,
                  const Variant &src_width,
                  const Variant &src_height);
Variant imagecopy(const Variant &dst_image,
                  const Variant &src_image,
                  const Variant &dst_x,
                  const Variant &dst_y,
                  const Variant &src_x,
                  const Variant &src_y,
                  const Variant &src_width,
                  const Variant &src_height);
Variant imagecopymerge(const GdImage &dst_image,
                       const GdImage &src_image,
                       const Variant &dst_x,
                       const Variant &dst_y,
                       const Variant &src_x,
                       const Variant &src_y,
                       const Variant &src_width,
                       const Variant &src_height,
                       const Variant &pct);
Variant imagecopymerge(const Variant &dst_image,
                       const Variant &src_image,
                       const Variant &dst_x,
                       const Variant &dst_y,
                       const Variant &src_x,
                       const Variant &src_y,
                       const Variant &src_width,
                       const Variant &src_height,
                       const Variant &pct);
Variant imagecopymergegray(const GdImage &dst_image,
                           const GdImage &src_image,
                           const Variant &dst_x,
                           const Variant &dst_y,
                           const Variant &src_x,
                           const Variant &src_y,
                           const Variant &src_width,
                           const Variant &src_height,
                           const Variant &pct);
Variant imagecopymergegray(const Variant &dst_image,
                           const Variant &src_image,
                           const Variant &dst_x,
                           const Variant &dst_y,
                           const Variant &src_x,
                           const Variant &src_y,
                           const Variant &src_width,
                           const Variant &src_height,
                           const Variant &pct);
Variant imagecopyresized(const GdImage &dst_image,
                         const GdImage &src_image,
                         const Variant &dst_x,
                         const Variant &dst_y,
                         const Variant &src_x,
                         const Variant &src_y,
                         const Variant &dst_width,
                         const Variant &dst_height,
                         const Variant &src_width,
                         const Variant &src_height);
Variant imagecopyresized(const Variant &dst_image,
                         const Variant &src_image,
                         const Variant &dst_x,
                         const Variant &dst_y,
                         const Variant &src_x,
                         const Variant &src_y,
                         const Variant &dst_width,
                         const Variant &dst_height,
                         const Variant &src_width,
                         const Variant &src_height);
Variant imagesx(const GdImage &image);
Variant imagesx(const Variant &image);
Variant imagesy(const GdImage &image);
Variant imagesy(const Variant &image);
Variant imagesetclip(const GdImage &image, const Variant &x1, const Variant &y1, const Variant &x2, const Variant &y2);
Variant imagesetclip(const Variant &image, const Variant &x1, const Variant &y1, const Variant &x2, const Variant &y2);
Variant imagegetclip(const GdImage &image);
Variant imagegetclip(const Variant &image);
template <typename... Args>
Variant imagefilter(const GdImage &image, const Variant &filter, const Args &...args) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[650]);
    }
    return call(fn, {image.getObject(), filter, args...});
}
Variant imageconvolution(const GdImage &image, const Variant &matrix, const Variant &divisor, const Variant &offset);
Variant imageconvolution(const Variant &image, const Variant &matrix, const Variant &divisor, const Variant &offset);
Variant imageflip(const GdImage &image, const Variant &mode);
Variant imageflip(const Variant &image, const Variant &mode);
Variant imageantialias(const GdImage &image, const Variant &enable);
Variant imageantialias(const Variant &image, const Variant &enable);
GdImage imagecrop(const GdImage &image, const Variant &rectangle);
Variant imagecrop(const Variant &image, const Variant &rectangle);
GdImage imagecropauto(const GdImage &image,
                      const Variant &mode = 0,
                      const Variant &threshold = 0.5,
                      const Variant &color = -1);
Variant imagecropauto(const Variant &image,
                      const Variant &mode = 0,
                      const Variant &threshold = 0.5,
                      const Variant &color = -1);
GdImage imagescale(const GdImage &image, const Variant &width, const Variant &height = -1, const Variant &mode = 3);
Variant imagescale(const Variant &image, const Variant &width, const Variant &height = -1, const Variant &mode = 3);
GdImage imageaffine(const GdImage &image, const Variant &affine, const Variant &clip = nullptr);
Variant imageaffine(const Variant &image, const Variant &affine, const Variant &clip = nullptr);
Variant imageaffinematrixget(const Variant &type, const Variant &options);
Variant imageaffinematrixconcat(const Variant &matrix1, const Variant &matrix2);
Variant imagegetinterpolation(const GdImage &image);
Variant imagegetinterpolation(const Variant &image);
Variant imagesetinterpolation(const GdImage &image, const Variant &method = 3);
Variant imagesetinterpolation(const Variant &image, const Variant &method = 3);
Variant imageresolution(const GdImage &image,
                        const Variant &resolution_x = nullptr,
                        const Variant &resolution_y = nullptr);
Variant imageresolution(const Variant &image,
                        const Variant &resolution_x = nullptr,
                        const Variant &resolution_y = nullptr);

}  // namespace php
