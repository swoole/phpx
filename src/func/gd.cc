#include "phpx.h"
#include "phpx_literal_string.h"

namespace php {
Variant gd_info() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[540]);
    }
    return call(fn, {});
}
Variant imageloadfont(const Variant &filename) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[541]);
    }
    return call(fn, {filename});
}
Variant imagesetstyle(const Variant &image, const Variant &style) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[542]);
    }
    return call(fn, {image, style});
}
Variant imagecreatetruecolor(const Variant &width, const Variant &height) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[543]);
    }
    return call(fn, {width, height});
}
Variant imageistruecolor(const Variant &image) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[544]);
    }
    return call(fn, {image});
}
Variant imagetruecolortopalette(const Variant &image, const Variant &dither, const Variant &num_colors) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[545]);
    }
    return call(fn, {image, dither, num_colors});
}
Variant imagepalettetotruecolor(const Variant &image) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[546]);
    }
    return call(fn, {image});
}
Variant imagecolormatch(const Variant &image1, const Variant &image2) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[547]);
    }
    return call(fn, {image1, image2});
}
Variant imagesetthickness(const Variant &image, const Variant &thickness) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[548]);
    }
    return call(fn, {image, thickness});
}
Variant imagefilledellipse(const Variant &image,
                           const Variant &center_x,
                           const Variant &center_y,
                           const Variant &width,
                           const Variant &height,
                           const Variant &color) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[549]);
    }
    return call(fn, {image, center_x, center_y, width, height, color});
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
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[550]);
    }
    return call(fn, {image, center_x, center_y, width, height, start_angle, end_angle, color, style});
}
Variant imagealphablending(const Variant &image, const Variant &enable) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[551]);
    }
    return call(fn, {image, enable});
}
Variant imagesavealpha(const Variant &image, const Variant &enable) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[552]);
    }
    return call(fn, {image, enable});
}
Variant imagelayereffect(const Variant &image, const Variant &effect) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[553]);
    }
    return call(fn, {image, effect});
}
Variant imagecolorallocatealpha(
    const Variant &image, const Variant &red, const Variant &green, const Variant &blue, const Variant &alpha) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[554]);
    }
    return call(fn, {image, red, green, blue, alpha});
}
Variant imagecolorresolvealpha(
    const Variant &image, const Variant &red, const Variant &green, const Variant &blue, const Variant &alpha) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[555]);
    }
    return call(fn, {image, red, green, blue, alpha});
}
Variant imagecolorclosestalpha(
    const Variant &image, const Variant &red, const Variant &green, const Variant &blue, const Variant &alpha) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[556]);
    }
    return call(fn, {image, red, green, blue, alpha});
}
Variant imagecolorexactalpha(
    const Variant &image, const Variant &red, const Variant &green, const Variant &blue, const Variant &alpha) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[557]);
    }
    return call(fn, {image, red, green, blue, alpha});
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
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[558]);
    }
    return call(fn, {dst_image, src_image, dst_x, dst_y, src_x, src_y, dst_width, dst_height, src_width, src_height});
}
Variant imagerotate(const Variant &image, const Variant &angle, const Variant &background_color) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[559]);
    }
    return call(fn, {image, angle, background_color});
}
Variant imagesettile(const Variant &image, const Variant &tile) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[560]);
    }
    return call(fn, {image, tile});
}
Variant imagesetbrush(const Variant &image, const Variant &brush) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[561]);
    }
    return call(fn, {image, brush});
}
Variant imagecreate(const Variant &width, const Variant &height) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[562]);
    }
    return call(fn, {width, height});
}
Variant imagetypes() {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[563]);
    }
    return call(fn, {});
}
Variant imagecreatefromstring(const Variant &data) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[564]);
    }
    return call(fn, {data});
}
Variant imagecreatefromgif(const Variant &filename) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[565]);
    }
    return call(fn, {filename});
}
Variant imagecreatefromjpeg(const Variant &filename) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[566]);
    }
    return call(fn, {filename});
}
Variant imagecreatefrompng(const Variant &filename) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[567]);
    }
    return call(fn, {filename});
}
Variant imagecreatefromwebp(const Variant &filename) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[568]);
    }
    return call(fn, {filename});
}
Variant imagecreatefromxbm(const Variant &filename) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[569]);
    }
    return call(fn, {filename});
}
Variant imagecreatefromwbmp(const Variant &filename) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[570]);
    }
    return call(fn, {filename});
}
Variant imagecreatefromgd(const Variant &filename) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[571]);
    }
    return call(fn, {filename});
}
Variant imagecreatefromgd2(const Variant &filename) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[572]);
    }
    return call(fn, {filename});
}
Variant imagecreatefromgd2part(
    const Variant &filename, const Variant &x, const Variant &y, const Variant &width, const Variant &height) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[573]);
    }
    return call(fn, {filename, x, y, width, height});
}
Variant imagecreatefrombmp(const Variant &filename) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[574]);
    }
    return call(fn, {filename});
}
Variant imagecreatefromtga(const Variant &filename) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[575]);
    }
    return call(fn, {filename});
}
Variant imagexbm(const Variant &image, const Variant &filename, const Variant &foreground_color) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[576]);
    }
    return call(fn, {image, filename, foreground_color});
}
Variant imagegif(const Variant &image, const Variant &file) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[577]);
    }
    return call(fn, {image, file});
}
Variant imagepng(const Variant &image, const Variant &file, const Variant &quality, const Variant &filters) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[578]);
    }
    return call(fn, {image, file, quality, filters});
}
Variant imagewebp(const Variant &image, const Variant &file, const Variant &quality) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[579]);
    }
    return call(fn, {image, file, quality});
}
Variant imagejpeg(const Variant &image, const Variant &file, const Variant &quality) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[580]);
    }
    return call(fn, {image, file, quality});
}
Variant imagewbmp(const Variant &image, const Variant &file, const Variant &foreground_color) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[581]);
    }
    return call(fn, {image, file, foreground_color});
}
Variant imagegd(const Variant &image, const Variant &file) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[582]);
    }
    return call(fn, {image, file});
}
Variant imagegd2(const Variant &image, const Variant &file, const Variant &chunk_size, const Variant &mode) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[583]);
    }
    return call(fn, {image, file, chunk_size, mode});
}
Variant imagebmp(const Variant &image, const Variant &file, const Variant &compressed) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[584]);
    }
    return call(fn, {image, file, compressed});
}
Variant imagedestroy(const Variant &image) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[585]);
    }
    return call(fn, {image});
}
Variant imagecolorallocate(const Variant &image, const Variant &red, const Variant &green, const Variant &blue) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[586]);
    }
    return call(fn, {image, red, green, blue});
}
Variant imagepalettecopy(const Variant &dst, const Variant &src) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[587]);
    }
    return call(fn, {dst, src});
}
Variant imagecolorat(const Variant &image, const Variant &x, const Variant &y) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[588]);
    }
    return call(fn, {image, x, y});
}
Variant imagecolorclosest(const Variant &image, const Variant &red, const Variant &green, const Variant &blue) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[589]);
    }
    return call(fn, {image, red, green, blue});
}
Variant imagecolorclosesthwb(const Variant &image, const Variant &red, const Variant &green, const Variant &blue) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[590]);
    }
    return call(fn, {image, red, green, blue});
}
Variant imagecolordeallocate(const Variant &image, const Variant &color) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[591]);
    }
    return call(fn, {image, color});
}
Variant imagecolorresolve(const Variant &image, const Variant &red, const Variant &green, const Variant &blue) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[592]);
    }
    return call(fn, {image, red, green, blue});
}
Variant imagecolorexact(const Variant &image, const Variant &red, const Variant &green, const Variant &blue) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[593]);
    }
    return call(fn, {image, red, green, blue});
}
Variant imagecolorset(const Variant &image,
                      const Variant &color,
                      const Variant &red,
                      const Variant &green,
                      const Variant &blue,
                      const Variant &alpha) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[594]);
    }
    return call(fn, {image, color, red, green, blue, alpha});
}
Variant imagecolorsforindex(const Variant &image, const Variant &color) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[595]);
    }
    return call(fn, {image, color});
}
Variant imagegammacorrect(const Variant &image, const Variant &input_gamma, const Variant &output_gamma) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[596]);
    }
    return call(fn, {image, input_gamma, output_gamma});
}
Variant imagesetpixel(const Variant &image, const Variant &x, const Variant &y, const Variant &color) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[597]);
    }
    return call(fn, {image, x, y, color});
}
Variant imageline(const Variant &image,
                  const Variant &x1,
                  const Variant &y1,
                  const Variant &x2,
                  const Variant &y2,
                  const Variant &color) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[598]);
    }
    return call(fn, {image, x1, y1, x2, y2, color});
}
Variant imagedashedline(const Variant &image,
                        const Variant &x1,
                        const Variant &y1,
                        const Variant &x2,
                        const Variant &y2,
                        const Variant &color) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[599]);
    }
    return call(fn, {image, x1, y1, x2, y2, color});
}
Variant imagerectangle(const Variant &image,
                       const Variant &x1,
                       const Variant &y1,
                       const Variant &x2,
                       const Variant &y2,
                       const Variant &color) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[600]);
    }
    return call(fn, {image, x1, y1, x2, y2, color});
}
Variant imagefilledrectangle(const Variant &image,
                             const Variant &x1,
                             const Variant &y1,
                             const Variant &x2,
                             const Variant &y2,
                             const Variant &color) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[601]);
    }
    return call(fn, {image, x1, y1, x2, y2, color});
}
Variant imagearc(const Variant &image,
                 const Variant &center_x,
                 const Variant &center_y,
                 const Variant &width,
                 const Variant &height,
                 const Variant &start_angle,
                 const Variant &end_angle,
                 const Variant &color) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[602]);
    }
    return call(fn, {image, center_x, center_y, width, height, start_angle, end_angle, color});
}
Variant imageellipse(const Variant &image,
                     const Variant &center_x,
                     const Variant &center_y,
                     const Variant &width,
                     const Variant &height,
                     const Variant &color) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[603]);
    }
    return call(fn, {image, center_x, center_y, width, height, color});
}
Variant imagefilltoborder(
    const Variant &image, const Variant &x, const Variant &y, const Variant &border_color, const Variant &color) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[604]);
    }
    return call(fn, {image, x, y, border_color, color});
}
Variant imagefill(const Variant &image, const Variant &x, const Variant &y, const Variant &color) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[605]);
    }
    return call(fn, {image, x, y, color});
}
Variant imagecolorstotal(const Variant &image) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[606]);
    }
    return call(fn, {image});
}
Variant imagecolortransparent(const Variant &image, const Variant &color) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[607]);
    }
    return call(fn, {image, color});
}
Variant imageinterlace(const Variant &image, const Variant &enable) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[608]);
    }
    return call(fn, {image, enable});
}
Variant imagepolygon(const Variant &image,
                     const Variant &points,
                     const Variant &num_points_or_color,
                     const Variant &color) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[609]);
    }
    return call(fn, {image, points, num_points_or_color, color});
}
Variant imageopenpolygon(const Variant &image,
                         const Variant &points,
                         const Variant &num_points_or_color,
                         const Variant &color) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[610]);
    }
    return call(fn, {image, points, num_points_or_color, color});
}
Variant imagefilledpolygon(const Variant &image,
                           const Variant &points,
                           const Variant &num_points_or_color,
                           const Variant &color) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[611]);
    }
    return call(fn, {image, points, num_points_or_color, color});
}
Variant imagefontwidth(const Variant &font) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[612]);
    }
    return call(fn, {font});
}
Variant imagefontheight(const Variant &font) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[613]);
    }
    return call(fn, {font});
}
Variant imagechar(const Variant &image,
                  const Variant &font,
                  const Variant &x,
                  const Variant &y,
                  const Variant &_char,
                  const Variant &color) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[614]);
    }
    return call(fn, {image, font, x, y, _char, color});
}
Variant imagecharup(const Variant &image,
                    const Variant &font,
                    const Variant &x,
                    const Variant &y,
                    const Variant &_char,
                    const Variant &color) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[615]);
    }
    return call(fn, {image, font, x, y, _char, color});
}
Variant imagestring(const Variant &image,
                    const Variant &font,
                    const Variant &x,
                    const Variant &y,
                    const Variant &string,
                    const Variant &color) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[616]);
    }
    return call(fn, {image, font, x, y, string, color});
}
Variant imagestringup(const Variant &image,
                      const Variant &font,
                      const Variant &x,
                      const Variant &y,
                      const Variant &string,
                      const Variant &color) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[617]);
    }
    return call(fn, {image, font, x, y, string, color});
}
Variant imagecopy(const Variant &dst_image,
                  const Variant &src_image,
                  const Variant &dst_x,
                  const Variant &dst_y,
                  const Variant &src_x,
                  const Variant &src_y,
                  const Variant &src_width,
                  const Variant &src_height) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[618]);
    }
    return call(fn, {dst_image, src_image, dst_x, dst_y, src_x, src_y, src_width, src_height});
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
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[619]);
    }
    return call(fn, {dst_image, src_image, dst_x, dst_y, src_x, src_y, src_width, src_height, pct});
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
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[620]);
    }
    return call(fn, {dst_image, src_image, dst_x, dst_y, src_x, src_y, src_width, src_height, pct});
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
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[621]);
    }
    return call(fn, {dst_image, src_image, dst_x, dst_y, src_x, src_y, dst_width, dst_height, src_width, src_height});
}
Variant imagesx(const Variant &image) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[622]);
    }
    return call(fn, {image});
}
Variant imagesy(const Variant &image) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[623]);
    }
    return call(fn, {image});
}
Variant imagesetclip(const Variant &image, const Variant &x1, const Variant &y1, const Variant &x2, const Variant &y2) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[624]);
    }
    return call(fn, {image, x1, y1, x2, y2});
}
Variant imagegetclip(const Variant &image) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[625]);
    }
    return call(fn, {image});
}
Variant imageconvolution(const Variant &image, const Variant &matrix, const Variant &divisor, const Variant &offset) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[627]);
    }
    return call(fn, {image, matrix, divisor, offset});
}
Variant imageflip(const Variant &image, const Variant &mode) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[628]);
    }
    return call(fn, {image, mode});
}
Variant imageantialias(const Variant &image, const Variant &enable) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[629]);
    }
    return call(fn, {image, enable});
}
Variant imagecrop(const Variant &image, const Variant &rectangle) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[630]);
    }
    return call(fn, {image, rectangle});
}
Variant imagecropauto(const Variant &image, const Variant &mode, const Variant &threshold, const Variant &color) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[631]);
    }
    return call(fn, {image, mode, threshold, color});
}
Variant imagescale(const Variant &image, const Variant &width, const Variant &height, const Variant &mode) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[632]);
    }
    return call(fn, {image, width, height, mode});
}
Variant imageaffine(const Variant &image, const Variant &affine, const Variant &clip) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[633]);
    }
    return call(fn, {image, affine, clip});
}
Variant imageaffinematrixget(const Variant &type, const Variant &options) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[634]);
    }
    return call(fn, {type, options});
}
Variant imageaffinematrixconcat(const Variant &matrix1, const Variant &matrix2) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[635]);
    }
    return call(fn, {matrix1, matrix2});
}
Variant imagegetinterpolation(const Variant &image) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[636]);
    }
    return call(fn, {image});
}
Variant imagesetinterpolation(const Variant &image, const Variant &method) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[637]);
    }
    return call(fn, {image, method});
}
Variant imageresolution(const Variant &image, const Variant &resolution_x, const Variant &resolution_y) {
    static THREAD_LOCAL zend_function *fn = nullptr;
    if (UNEXPECTED(!fn)) {
        fn = getFunction(LITERAL_STRING[638]);
    }
    return call(fn, {image, resolution_x, resolution_y});
}
}  // namespace php
