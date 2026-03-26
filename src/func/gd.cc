#include "phpx.h"
#include "phpx_literal_string.h"

namespace php {
Variant gd_info() {
    return call(LITERAL_STRING[509], {});
}
Variant imageloadfont(const Variant &filename) {
    return call(LITERAL_STRING[510], {filename});
}
Variant imagesetstyle(const Variant &image, const Variant &style) {
    return call(LITERAL_STRING[511], {image, style});
}
Variant imagecreatetruecolor(const Variant &width, const Variant &height) {
    return call(LITERAL_STRING[512], {width, height});
}
Variant imageistruecolor(const Variant &image) {
    return call(LITERAL_STRING[513], {image});
}
Variant imagetruecolortopalette(const Variant &image, const Variant &dither, const Variant &num_colors) {
    return call(LITERAL_STRING[514], {image, dither, num_colors});
}
Variant imagepalettetotruecolor(const Variant &image) {
    return call(LITERAL_STRING[515], {image});
}
Variant imagecolormatch(const Variant &image1, const Variant &image2) {
    return call(LITERAL_STRING[516], {image1, image2});
}
Variant imagesetthickness(const Variant &image, const Variant &thickness) {
    return call(LITERAL_STRING[517], {image, thickness});
}
Variant imagefilledellipse(const Variant &image,
                           const Variant &center_x,
                           const Variant &center_y,
                           const Variant &width,
                           const Variant &height,
                           const Variant &color) {
    return call(LITERAL_STRING[518], {image, center_x, center_y, width, height, color});
}
Variant imagefilledarc(const Variant &image,
                       const Variant &center_x,
                       const Variant &center_y,
                       const Variant &width,
                       const Variant &height,
                       const Variant &start_angle,
                       const Variant &end_angle,
                       const Variant &color,
                       const Variant &style) {
    return call(LITERAL_STRING[519], {image, center_x, center_y, width, height, start_angle, end_angle, color, style});
}
Variant imagealphablending(const Variant &image, const Variant &enable) {
    return call(LITERAL_STRING[520], {image, enable});
}
Variant imagesavealpha(const Variant &image, const Variant &enable) {
    return call(LITERAL_STRING[521], {image, enable});
}
Variant imagelayereffect(const Variant &image, const Variant &effect) {
    return call(LITERAL_STRING[522], {image, effect});
}
Variant imagecolorallocatealpha(
    const Variant &image, const Variant &red, const Variant &green, const Variant &blue, const Variant &alpha) {
    return call(LITERAL_STRING[523], {image, red, green, blue, alpha});
}
Variant imagecolorresolvealpha(
    const Variant &image, const Variant &red, const Variant &green, const Variant &blue, const Variant &alpha) {
    return call(LITERAL_STRING[524], {image, red, green, blue, alpha});
}
Variant imagecolorclosestalpha(
    const Variant &image, const Variant &red, const Variant &green, const Variant &blue, const Variant &alpha) {
    return call(LITERAL_STRING[525], {image, red, green, blue, alpha});
}
Variant imagecolorexactalpha(
    const Variant &image, const Variant &red, const Variant &green, const Variant &blue, const Variant &alpha) {
    return call(LITERAL_STRING[526], {image, red, green, blue, alpha});
}
Variant imagecopyresampled(const Variant &dst_image,
                           const Variant &src_image,
                           const Variant &dst_x,
                           const Variant &dst_y,
                           const Variant &src_x,
                           const Variant &src_y,
                           const Variant &dst_width,
                           const Variant &dst_height,
                           const Variant &src_width,
                           const Variant &src_height) {
    return call(LITERAL_STRING[527],
                {dst_image, src_image, dst_x, dst_y, src_x, src_y, dst_width, dst_height, src_width, src_height});
}
Variant imagerotate(const Variant &image, const Variant &angle, const Variant &background_color) {
    return call(LITERAL_STRING[528], {image, angle, background_color});
}
Variant imagesettile(const Variant &image, const Variant &tile) {
    return call(LITERAL_STRING[529], {image, tile});
}
Variant imagesetbrush(const Variant &image, const Variant &brush) {
    return call(LITERAL_STRING[530], {image, brush});
}
Variant imagecreate(const Variant &width, const Variant &height) {
    return call(LITERAL_STRING[531], {width, height});
}
Variant imagetypes() {
    return call(LITERAL_STRING[532], {});
}
Variant imagecreatefromstring(const Variant &data) {
    return call(LITERAL_STRING[533], {data});
}
Variant imagecreatefromgif(const Variant &filename) {
    return call(LITERAL_STRING[534], {filename});
}
Variant imagecreatefromjpeg(const Variant &filename) {
    return call(LITERAL_STRING[535], {filename});
}
Variant imagecreatefrompng(const Variant &filename) {
    return call(LITERAL_STRING[536], {filename});
}
Variant imagecreatefromwebp(const Variant &filename) {
    return call(LITERAL_STRING[537], {filename});
}
Variant imagecreatefromxbm(const Variant &filename) {
    return call(LITERAL_STRING[538], {filename});
}
Variant imagecreatefromwbmp(const Variant &filename) {
    return call(LITERAL_STRING[539], {filename});
}
Variant imagecreatefromgd(const Variant &filename) {
    return call(LITERAL_STRING[540], {filename});
}
Variant imagecreatefromgd2(const Variant &filename) {
    return call(LITERAL_STRING[541], {filename});
}
Variant imagecreatefromgd2part(
    const Variant &filename, const Variant &x, const Variant &y, const Variant &width, const Variant &height) {
    return call(LITERAL_STRING[542], {filename, x, y, width, height});
}
Variant imagecreatefrombmp(const Variant &filename) {
    return call(LITERAL_STRING[543], {filename});
}
Variant imagecreatefromtga(const Variant &filename) {
    return call(LITERAL_STRING[544], {filename});
}
Variant imagexbm(const Variant &image, const Variant &filename, const Variant &foreground_color) {
    return call(LITERAL_STRING[545], {image, filename, foreground_color});
}
Variant imagegif(const Variant &image, const Variant &file) {
    return call(LITERAL_STRING[546], {image, file});
}
Variant imagepng(const Variant &image, const Variant &file, const Variant &quality, const Variant &filters) {
    return call(LITERAL_STRING[547], {image, file, quality, filters});
}
Variant imagewebp(const Variant &image, const Variant &file, const Variant &quality) {
    return call(LITERAL_STRING[548], {image, file, quality});
}
Variant imagejpeg(const Variant &image, const Variant &file, const Variant &quality) {
    return call(LITERAL_STRING[549], {image, file, quality});
}
Variant imagewbmp(const Variant &image, const Variant &file, const Variant &foreground_color) {
    return call(LITERAL_STRING[550], {image, file, foreground_color});
}
Variant imagegd(const Variant &image, const Variant &file) {
    return call(LITERAL_STRING[551], {image, file});
}
Variant imagegd2(const Variant &image, const Variant &file, const Variant &chunk_size, const Variant &mode) {
    return call(LITERAL_STRING[552], {image, file, chunk_size, mode});
}
Variant imagebmp(const Variant &image, const Variant &file, const Variant &compressed) {
    return call(LITERAL_STRING[553], {image, file, compressed});
}
Variant imagedestroy(const Variant &image) {
    return call(LITERAL_STRING[554], {image});
}
Variant imagecolorallocate(const Variant &image, const Variant &red, const Variant &green, const Variant &blue) {
    return call(LITERAL_STRING[555], {image, red, green, blue});
}
Variant imagepalettecopy(const Variant &dst, const Variant &src) {
    return call(LITERAL_STRING[556], {dst, src});
}
Variant imagecolorat(const Variant &image, const Variant &x, const Variant &y) {
    return call(LITERAL_STRING[557], {image, x, y});
}
Variant imagecolorclosest(const Variant &image, const Variant &red, const Variant &green, const Variant &blue) {
    return call(LITERAL_STRING[558], {image, red, green, blue});
}
Variant imagecolorclosesthwb(const Variant &image, const Variant &red, const Variant &green, const Variant &blue) {
    return call(LITERAL_STRING[559], {image, red, green, blue});
}
Variant imagecolordeallocate(const Variant &image, const Variant &color) {
    return call(LITERAL_STRING[560], {image, color});
}
Variant imagecolorresolve(const Variant &image, const Variant &red, const Variant &green, const Variant &blue) {
    return call(LITERAL_STRING[561], {image, red, green, blue});
}
Variant imagecolorexact(const Variant &image, const Variant &red, const Variant &green, const Variant &blue) {
    return call(LITERAL_STRING[562], {image, red, green, blue});
}
Variant imagecolorset(const Variant &image,
                      const Variant &color,
                      const Variant &red,
                      const Variant &green,
                      const Variant &blue,
                      const Variant &alpha) {
    return call(LITERAL_STRING[563], {image, color, red, green, blue, alpha});
}
Variant imagecolorsforindex(const Variant &image, const Variant &color) {
    return call(LITERAL_STRING[564], {image, color});
}
Variant imagegammacorrect(const Variant &image, const Variant &input_gamma, const Variant &output_gamma) {
    return call(LITERAL_STRING[565], {image, input_gamma, output_gamma});
}
Variant imagesetpixel(const Variant &image, const Variant &x, const Variant &y, const Variant &color) {
    return call(LITERAL_STRING[566], {image, x, y, color});
}
Variant imageline(const Variant &image,
                  const Variant &x1,
                  const Variant &y1,
                  const Variant &x2,
                  const Variant &y2,
                  const Variant &color) {
    return call(LITERAL_STRING[567], {image, x1, y1, x2, y2, color});
}
Variant imagedashedline(const Variant &image,
                        const Variant &x1,
                        const Variant &y1,
                        const Variant &x2,
                        const Variant &y2,
                        const Variant &color) {
    return call(LITERAL_STRING[568], {image, x1, y1, x2, y2, color});
}
Variant imagerectangle(const Variant &image,
                       const Variant &x1,
                       const Variant &y1,
                       const Variant &x2,
                       const Variant &y2,
                       const Variant &color) {
    return call(LITERAL_STRING[569], {image, x1, y1, x2, y2, color});
}
Variant imagefilledrectangle(const Variant &image,
                             const Variant &x1,
                             const Variant &y1,
                             const Variant &x2,
                             const Variant &y2,
                             const Variant &color) {
    return call(LITERAL_STRING[570], {image, x1, y1, x2, y2, color});
}
Variant imagearc(const Variant &image,
                 const Variant &center_x,
                 const Variant &center_y,
                 const Variant &width,
                 const Variant &height,
                 const Variant &start_angle,
                 const Variant &end_angle,
                 const Variant &color) {
    return call(LITERAL_STRING[571], {image, center_x, center_y, width, height, start_angle, end_angle, color});
}
Variant imageellipse(const Variant &image,
                     const Variant &center_x,
                     const Variant &center_y,
                     const Variant &width,
                     const Variant &height,
                     const Variant &color) {
    return call(LITERAL_STRING[572], {image, center_x, center_y, width, height, color});
}
Variant imagefilltoborder(
    const Variant &image, const Variant &x, const Variant &y, const Variant &border_color, const Variant &color) {
    return call(LITERAL_STRING[573], {image, x, y, border_color, color});
}
Variant imagefill(const Variant &image, const Variant &x, const Variant &y, const Variant &color) {
    return call(LITERAL_STRING[574], {image, x, y, color});
}
Variant imagecolorstotal(const Variant &image) {
    return call(LITERAL_STRING[575], {image});
}
Variant imagecolortransparent(const Variant &image, const Variant &color) {
    return call(LITERAL_STRING[576], {image, color});
}
Variant imageinterlace(const Variant &image, const Variant &enable) {
    return call(LITERAL_STRING[577], {image, enable});
}
Variant imagepolygon(const Variant &image,
                     const Variant &points,
                     const Variant &num_points_or_color,
                     const Variant &color) {
    return call(LITERAL_STRING[578], {image, points, num_points_or_color, color});
}
Variant imageopenpolygon(const Variant &image,
                         const Variant &points,
                         const Variant &num_points_or_color,
                         const Variant &color) {
    return call(LITERAL_STRING[579], {image, points, num_points_or_color, color});
}
Variant imagefilledpolygon(const Variant &image,
                           const Variant &points,
                           const Variant &num_points_or_color,
                           const Variant &color) {
    return call(LITERAL_STRING[580], {image, points, num_points_or_color, color});
}
Variant imagefontwidth(const Variant &font) {
    return call(LITERAL_STRING[581], {font});
}
Variant imagefontheight(const Variant &font) {
    return call(LITERAL_STRING[582], {font});
}
Variant imagechar(const Variant &image,
                  const Variant &font,
                  const Variant &x,
                  const Variant &y,
                  const Variant &_char,
                  const Variant &color) {
    return call(LITERAL_STRING[583], {image, font, x, y, _char, color});
}
Variant imagecharup(const Variant &image,
                    const Variant &font,
                    const Variant &x,
                    const Variant &y,
                    const Variant &_char,
                    const Variant &color) {
    return call(LITERAL_STRING[584], {image, font, x, y, _char, color});
}
Variant imagestring(const Variant &image,
                    const Variant &font,
                    const Variant &x,
                    const Variant &y,
                    const Variant &string,
                    const Variant &color) {
    return call(LITERAL_STRING[585], {image, font, x, y, string, color});
}
Variant imagestringup(const Variant &image,
                      const Variant &font,
                      const Variant &x,
                      const Variant &y,
                      const Variant &string,
                      const Variant &color) {
    return call(LITERAL_STRING[586], {image, font, x, y, string, color});
}
Variant imagecopy(const Variant &dst_image,
                  const Variant &src_image,
                  const Variant &dst_x,
                  const Variant &dst_y,
                  const Variant &src_x,
                  const Variant &src_y,
                  const Variant &src_width,
                  const Variant &src_height) {
    return call(LITERAL_STRING[587], {dst_image, src_image, dst_x, dst_y, src_x, src_y, src_width, src_height});
}
Variant imagecopymerge(const Variant &dst_image,
                       const Variant &src_image,
                       const Variant &dst_x,
                       const Variant &dst_y,
                       const Variant &src_x,
                       const Variant &src_y,
                       const Variant &src_width,
                       const Variant &src_height,
                       const Variant &pct) {
    return call(LITERAL_STRING[588], {dst_image, src_image, dst_x, dst_y, src_x, src_y, src_width, src_height, pct});
}
Variant imagecopymergegray(const Variant &dst_image,
                           const Variant &src_image,
                           const Variant &dst_x,
                           const Variant &dst_y,
                           const Variant &src_x,
                           const Variant &src_y,
                           const Variant &src_width,
                           const Variant &src_height,
                           const Variant &pct) {
    return call(LITERAL_STRING[589], {dst_image, src_image, dst_x, dst_y, src_x, src_y, src_width, src_height, pct});
}
Variant imagecopyresized(const Variant &dst_image,
                         const Variant &src_image,
                         const Variant &dst_x,
                         const Variant &dst_y,
                         const Variant &src_x,
                         const Variant &src_y,
                         const Variant &dst_width,
                         const Variant &dst_height,
                         const Variant &src_width,
                         const Variant &src_height) {
    return call(LITERAL_STRING[590],
                {dst_image, src_image, dst_x, dst_y, src_x, src_y, dst_width, dst_height, src_width, src_height});
}
Variant imagesx(const Variant &image) {
    return call(LITERAL_STRING[591], {image});
}
Variant imagesy(const Variant &image) {
    return call(LITERAL_STRING[592], {image});
}
Variant imagesetclip(const Variant &image, const Variant &x1, const Variant &y1, const Variant &x2, const Variant &y2) {
    return call(LITERAL_STRING[593], {image, x1, y1, x2, y2});
}
Variant imagegetclip(const Variant &image) {
    return call(LITERAL_STRING[594], {image});
}
Variant imageconvolution(const Variant &image, const Variant &matrix, const Variant &divisor, const Variant &offset) {
    return call(LITERAL_STRING[596], {image, matrix, divisor, offset});
}
Variant imageflip(const Variant &image, const Variant &mode) {
    return call(LITERAL_STRING[597], {image, mode});
}
Variant imageantialias(const Variant &image, const Variant &enable) {
    return call(LITERAL_STRING[598], {image, enable});
}
Variant imagecrop(const Variant &image, const Variant &rectangle) {
    return call(LITERAL_STRING[599], {image, rectangle});
}
Variant imagecropauto(const Variant &image, const Variant &mode, const Variant &threshold, const Variant &color) {
    return call(LITERAL_STRING[600], {image, mode, threshold, color});
}
Variant imagescale(const Variant &image, const Variant &width, const Variant &height, const Variant &mode) {
    return call(LITERAL_STRING[601], {image, width, height, mode});
}
Variant imageaffine(const Variant &image, const Variant &affine, const Variant &clip) {
    return call(LITERAL_STRING[602], {image, affine, clip});
}
Variant imageaffinematrixget(const Variant &type, const Variant &options) {
    return call(LITERAL_STRING[603], {type, options});
}
Variant imageaffinematrixconcat(const Variant &matrix1, const Variant &matrix2) {
    return call(LITERAL_STRING[604], {matrix1, matrix2});
}
Variant imagegetinterpolation(const Variant &image) {
    return call(LITERAL_STRING[605], {image});
}
Variant imagesetinterpolation(const Variant &image, const Variant &method) {
    return call(LITERAL_STRING[606], {image, method});
}
Variant imageresolution(const Variant &image, const Variant &resolution_x, const Variant &resolution_y) {
    return call(LITERAL_STRING[607], {image, resolution_x, resolution_y});
}
}  // namespace php
