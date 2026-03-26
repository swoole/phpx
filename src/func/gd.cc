#include "phpx.h"

namespace php {
Variant gd_info() {
    return call("gd_info", {});
}
Variant imageloadfont(const Variant &filename) {
    return call("imageloadfont", {filename});
}
Variant imagesetstyle(const Variant &image, const Variant &style) {
    return call("imagesetstyle", {image, style});
}
Variant imagecreatetruecolor(const Variant &width, const Variant &height) {
    return call("imagecreatetruecolor", {width, height});
}
Variant imageistruecolor(const Variant &image) {
    return call("imageistruecolor", {image});
}
Variant imagetruecolortopalette(const Variant &image, const Variant &dither, const Variant &num_colors) {
    return call("imagetruecolortopalette", {image, dither, num_colors});
}
Variant imagepalettetotruecolor(const Variant &image) {
    return call("imagepalettetotruecolor", {image});
}
Variant imagecolormatch(const Variant &image1, const Variant &image2) {
    return call("imagecolormatch", {image1, image2});
}
Variant imagesetthickness(const Variant &image, const Variant &thickness) {
    return call("imagesetthickness", {image, thickness});
}
Variant imagefilledellipse(const Variant &image, const Variant &center_x, const Variant &center_y, const Variant &width, const Variant &height, const Variant &color) {
    return call("imagefilledellipse", {image, center_x, center_y, width, height, color});
}
Variant imagefilledarc(const Variant &image, const Variant &center_x, const Variant &center_y, const Variant &width, const Variant &height, const Variant &start_angle, const Variant &end_angle, const Variant &color, const Variant &style) {
    return call("imagefilledarc", {image, center_x, center_y, width, height, start_angle, end_angle, color, style});
}
Variant imagealphablending(const Variant &image, const Variant &enable) {
    return call("imagealphablending", {image, enable});
}
Variant imagesavealpha(const Variant &image, const Variant &enable) {
    return call("imagesavealpha", {image, enable});
}
Variant imagelayereffect(const Variant &image, const Variant &effect) {
    return call("imagelayereffect", {image, effect});
}
Variant imagecolorallocatealpha(const Variant &image, const Variant &red, const Variant &green, const Variant &blue, const Variant &alpha) {
    return call("imagecolorallocatealpha", {image, red, green, blue, alpha});
}
Variant imagecolorresolvealpha(const Variant &image, const Variant &red, const Variant &green, const Variant &blue, const Variant &alpha) {
    return call("imagecolorresolvealpha", {image, red, green, blue, alpha});
}
Variant imagecolorclosestalpha(const Variant &image, const Variant &red, const Variant &green, const Variant &blue, const Variant &alpha) {
    return call("imagecolorclosestalpha", {image, red, green, blue, alpha});
}
Variant imagecolorexactalpha(const Variant &image, const Variant &red, const Variant &green, const Variant &blue, const Variant &alpha) {
    return call("imagecolorexactalpha", {image, red, green, blue, alpha});
}
Variant imagecopyresampled(const Variant &dst_image, const Variant &src_image, const Variant &dst_x, const Variant &dst_y, const Variant &src_x, const Variant &src_y, const Variant &dst_width, const Variant &dst_height, const Variant &src_width, const Variant &src_height) {
    return call("imagecopyresampled", {dst_image, src_image, dst_x, dst_y, src_x, src_y, dst_width, dst_height, src_width, src_height});
}
Variant imagerotate(const Variant &image, const Variant &angle, const Variant &background_color) {
    return call("imagerotate", {image, angle, background_color});
}
Variant imagesettile(const Variant &image, const Variant &tile) {
    return call("imagesettile", {image, tile});
}
Variant imagesetbrush(const Variant &image, const Variant &brush) {
    return call("imagesetbrush", {image, brush});
}
Variant imagecreate(const Variant &width, const Variant &height) {
    return call("imagecreate", {width, height});
}
Variant imagetypes() {
    return call("imagetypes", {});
}
Variant imagecreatefromstring(const Variant &data) {
    return call("imagecreatefromstring", {data});
}
Variant imagecreatefromgif(const Variant &filename) {
    return call("imagecreatefromgif", {filename});
}
Variant imagecreatefromjpeg(const Variant &filename) {
    return call("imagecreatefromjpeg", {filename});
}
Variant imagecreatefrompng(const Variant &filename) {
    return call("imagecreatefrompng", {filename});
}
Variant imagecreatefromwebp(const Variant &filename) {
    return call("imagecreatefromwebp", {filename});
}
Variant imagecreatefromxbm(const Variant &filename) {
    return call("imagecreatefromxbm", {filename});
}
Variant imagecreatefromwbmp(const Variant &filename) {
    return call("imagecreatefromwbmp", {filename});
}
Variant imagecreatefromgd(const Variant &filename) {
    return call("imagecreatefromgd", {filename});
}
Variant imagecreatefromgd2(const Variant &filename) {
    return call("imagecreatefromgd2", {filename});
}
Variant imagecreatefromgd2part(const Variant &filename, const Variant &x, const Variant &y, const Variant &width, const Variant &height) {
    return call("imagecreatefromgd2part", {filename, x, y, width, height});
}
Variant imagecreatefrombmp(const Variant &filename) {
    return call("imagecreatefrombmp", {filename});
}
Variant imagecreatefromtga(const Variant &filename) {
    return call("imagecreatefromtga", {filename});
}
Variant imagexbm(const Variant &image, const Variant &filename, const Variant &foreground_color) {
    return call("imagexbm", {image, filename, foreground_color});
}
Variant imagegif(const Variant &image, const Variant &file) {
    return call("imagegif", {image, file});
}
Variant imagepng(const Variant &image, const Variant &file, const Variant &quality, const Variant &filters) {
    return call("imagepng", {image, file, quality, filters});
}
Variant imagewebp(const Variant &image, const Variant &file, const Variant &quality) {
    return call("imagewebp", {image, file, quality});
}
Variant imagejpeg(const Variant &image, const Variant &file, const Variant &quality) {
    return call("imagejpeg", {image, file, quality});
}
Variant imagewbmp(const Variant &image, const Variant &file, const Variant &foreground_color) {
    return call("imagewbmp", {image, file, foreground_color});
}
Variant imagegd(const Variant &image, const Variant &file) {
    return call("imagegd", {image, file});
}
Variant imagegd2(const Variant &image, const Variant &file, const Variant &chunk_size, const Variant &mode) {
    return call("imagegd2", {image, file, chunk_size, mode});
}
Variant imagebmp(const Variant &image, const Variant &file, const Variant &compressed) {
    return call("imagebmp", {image, file, compressed});
}
Variant imagedestroy(const Variant &image) {
    return call("imagedestroy", {image});
}
Variant imagecolorallocate(const Variant &image, const Variant &red, const Variant &green, const Variant &blue) {
    return call("imagecolorallocate", {image, red, green, blue});
}
Variant imagepalettecopy(const Variant &dst, const Variant &src) {
    return call("imagepalettecopy", {dst, src});
}
Variant imagecolorat(const Variant &image, const Variant &x, const Variant &y) {
    return call("imagecolorat", {image, x, y});
}
Variant imagecolorclosest(const Variant &image, const Variant &red, const Variant &green, const Variant &blue) {
    return call("imagecolorclosest", {image, red, green, blue});
}
Variant imagecolorclosesthwb(const Variant &image, const Variant &red, const Variant &green, const Variant &blue) {
    return call("imagecolorclosesthwb", {image, red, green, blue});
}
Variant imagecolordeallocate(const Variant &image, const Variant &color) {
    return call("imagecolordeallocate", {image, color});
}
Variant imagecolorresolve(const Variant &image, const Variant &red, const Variant &green, const Variant &blue) {
    return call("imagecolorresolve", {image, red, green, blue});
}
Variant imagecolorexact(const Variant &image, const Variant &red, const Variant &green, const Variant &blue) {
    return call("imagecolorexact", {image, red, green, blue});
}
Variant imagecolorset(const Variant &image, const Variant &color, const Variant &red, const Variant &green, const Variant &blue, const Variant &alpha) {
    return call("imagecolorset", {image, color, red, green, blue, alpha});
}
Variant imagecolorsforindex(const Variant &image, const Variant &color) {
    return call("imagecolorsforindex", {image, color});
}
Variant imagegammacorrect(const Variant &image, const Variant &input_gamma, const Variant &output_gamma) {
    return call("imagegammacorrect", {image, input_gamma, output_gamma});
}
Variant imagesetpixel(const Variant &image, const Variant &x, const Variant &y, const Variant &color) {
    return call("imagesetpixel", {image, x, y, color});
}
Variant imageline(const Variant &image, const Variant &x1, const Variant &y1, const Variant &x2, const Variant &y2, const Variant &color) {
    return call("imageline", {image, x1, y1, x2, y2, color});
}
Variant imagedashedline(const Variant &image, const Variant &x1, const Variant &y1, const Variant &x2, const Variant &y2, const Variant &color) {
    return call("imagedashedline", {image, x1, y1, x2, y2, color});
}
Variant imagerectangle(const Variant &image, const Variant &x1, const Variant &y1, const Variant &x2, const Variant &y2, const Variant &color) {
    return call("imagerectangle", {image, x1, y1, x2, y2, color});
}
Variant imagefilledrectangle(const Variant &image, const Variant &x1, const Variant &y1, const Variant &x2, const Variant &y2, const Variant &color) {
    return call("imagefilledrectangle", {image, x1, y1, x2, y2, color});
}
Variant imagearc(const Variant &image, const Variant &center_x, const Variant &center_y, const Variant &width, const Variant &height, const Variant &start_angle, const Variant &end_angle, const Variant &color) {
    return call("imagearc", {image, center_x, center_y, width, height, start_angle, end_angle, color});
}
Variant imageellipse(const Variant &image, const Variant &center_x, const Variant &center_y, const Variant &width, const Variant &height, const Variant &color) {
    return call("imageellipse", {image, center_x, center_y, width, height, color});
}
Variant imagefilltoborder(const Variant &image, const Variant &x, const Variant &y, const Variant &border_color, const Variant &color) {
    return call("imagefilltoborder", {image, x, y, border_color, color});
}
Variant imagefill(const Variant &image, const Variant &x, const Variant &y, const Variant &color) {
    return call("imagefill", {image, x, y, color});
}
Variant imagecolorstotal(const Variant &image) {
    return call("imagecolorstotal", {image});
}
Variant imagecolortransparent(const Variant &image, const Variant &color) {
    return call("imagecolortransparent", {image, color});
}
Variant imageinterlace(const Variant &image, const Variant &enable) {
    return call("imageinterlace", {image, enable});
}
Variant imagepolygon(const Variant &image, const Variant &points, const Variant &num_points_or_color, const Variant &color) {
    return call("imagepolygon", {image, points, num_points_or_color, color});
}
Variant imageopenpolygon(const Variant &image, const Variant &points, const Variant &num_points_or_color, const Variant &color) {
    return call("imageopenpolygon", {image, points, num_points_or_color, color});
}
Variant imagefilledpolygon(const Variant &image, const Variant &points, const Variant &num_points_or_color, const Variant &color) {
    return call("imagefilledpolygon", {image, points, num_points_or_color, color});
}
Variant imagefontwidth(const Variant &font) {
    return call("imagefontwidth", {font});
}
Variant imagefontheight(const Variant &font) {
    return call("imagefontheight", {font});
}
Variant imagechar(const Variant &image, const Variant &font, const Variant &x, const Variant &y, const Variant &_char, const Variant &color) {
    return call("imagechar", {image, font, x, y, _char, color});
}
Variant imagecharup(const Variant &image, const Variant &font, const Variant &x, const Variant &y, const Variant &_char, const Variant &color) {
    return call("imagecharup", {image, font, x, y, _char, color});
}
Variant imagestring(const Variant &image, const Variant &font, const Variant &x, const Variant &y, const Variant &string, const Variant &color) {
    return call("imagestring", {image, font, x, y, string, color});
}
Variant imagestringup(const Variant &image, const Variant &font, const Variant &x, const Variant &y, const Variant &string, const Variant &color) {
    return call("imagestringup", {image, font, x, y, string, color});
}
Variant imagecopy(const Variant &dst_image, const Variant &src_image, const Variant &dst_x, const Variant &dst_y, const Variant &src_x, const Variant &src_y, const Variant &src_width, const Variant &src_height) {
    return call("imagecopy", {dst_image, src_image, dst_x, dst_y, src_x, src_y, src_width, src_height});
}
Variant imagecopymerge(const Variant &dst_image, const Variant &src_image, const Variant &dst_x, const Variant &dst_y, const Variant &src_x, const Variant &src_y, const Variant &src_width, const Variant &src_height, const Variant &pct) {
    return call("imagecopymerge", {dst_image, src_image, dst_x, dst_y, src_x, src_y, src_width, src_height, pct});
}
Variant imagecopymergegray(const Variant &dst_image, const Variant &src_image, const Variant &dst_x, const Variant &dst_y, const Variant &src_x, const Variant &src_y, const Variant &src_width, const Variant &src_height, const Variant &pct) {
    return call("imagecopymergegray", {dst_image, src_image, dst_x, dst_y, src_x, src_y, src_width, src_height, pct});
}
Variant imagecopyresized(const Variant &dst_image, const Variant &src_image, const Variant &dst_x, const Variant &dst_y, const Variant &src_x, const Variant &src_y, const Variant &dst_width, const Variant &dst_height, const Variant &src_width, const Variant &src_height) {
    return call("imagecopyresized", {dst_image, src_image, dst_x, dst_y, src_x, src_y, dst_width, dst_height, src_width, src_height});
}
Variant imagesx(const Variant &image) {
    return call("imagesx", {image});
}
Variant imagesy(const Variant &image) {
    return call("imagesy", {image});
}
Variant imagesetclip(const Variant &image, const Variant &x1, const Variant &y1, const Variant &x2, const Variant &y2) {
    return call("imagesetclip", {image, x1, y1, x2, y2});
}
Variant imagegetclip(const Variant &image) {
    return call("imagegetclip", {image});
}
Variant imageconvolution(const Variant &image, const Variant &matrix, const Variant &divisor, const Variant &offset) {
    return call("imageconvolution", {image, matrix, divisor, offset});
}
Variant imageflip(const Variant &image, const Variant &mode) {
    return call("imageflip", {image, mode});
}
Variant imageantialias(const Variant &image, const Variant &enable) {
    return call("imageantialias", {image, enable});
}
Variant imagecrop(const Variant &image, const Variant &rectangle) {
    return call("imagecrop", {image, rectangle});
}
Variant imagecropauto(const Variant &image, const Variant &mode, const Variant &threshold, const Variant &color) {
    return call("imagecropauto", {image, mode, threshold, color});
}
Variant imagescale(const Variant &image, const Variant &width, const Variant &height, const Variant &mode) {
    return call("imagescale", {image, width, height, mode});
}
Variant imageaffine(const Variant &image, const Variant &affine, const Variant &clip) {
    return call("imageaffine", {image, affine, clip});
}
Variant imageaffinematrixget(const Variant &type, const Variant &options) {
    return call("imageaffinematrixget", {type, options});
}
Variant imageaffinematrixconcat(const Variant &matrix1, const Variant &matrix2) {
    return call("imageaffinematrixconcat", {matrix1, matrix2});
}
Variant imagegetinterpolation(const Variant &image) {
    return call("imagegetinterpolation", {image});
}
Variant imagesetinterpolation(const Variant &image, const Variant &method) {
    return call("imagesetinterpolation", {image, method});
}
Variant imageresolution(const Variant &image, const Variant &resolution_x, const Variant &resolution_y) {
    return call("imageresolution", {image, resolution_x, resolution_y});
}
}
