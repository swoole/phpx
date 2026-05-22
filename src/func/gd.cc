#include "phpx.h"
#include "phpx_literal_string.h"
#include "phpx_class.h"

namespace php {
Variant gd_info() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[564]);
    }
    return call(_fn, {});
}
GdFont imageloadfont(const Variant &filename) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[565]);
    }
    auto _rv = call(_fn, {filename});
    if (!_rv.toBool()) {
        throwException(String("RuntimeException"), "imageloadfont() returned false");
    }
    return GdFont(Object(std::move(_rv)));
}
Variant imagesetstyle(const GdImage &image, const Variant &style) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[566]);
    }
    return call(_fn, {image.getObject(), style});
}
Variant imagesetstyle(const Variant &image, const Variant &style) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[566]);
    }
    return call(_fn, {image, style});
}
GdImage imagecreatetruecolor(const Variant &width, const Variant &height) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[567]);
    }
    auto _rv = call(_fn, {width, height});
    if (!_rv.toBool()) {
        throwException(String("RuntimeException"), "imagecreatetruecolor() returned false");
    }
    return GdImage(Object(std::move(_rv)));
}
Variant imageistruecolor(const GdImage &image) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[568]);
    }
    return call(_fn, {image.getObject()});
}
Variant imageistruecolor(const Variant &image) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[568]);
    }
    return call(_fn, {image});
}
Variant imagetruecolortopalette(const GdImage &image, const Variant &dither, const Variant &num_colors) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[569]);
    }
    return call(_fn, {image.getObject(), dither, num_colors});
}
Variant imagetruecolortopalette(const Variant &image, const Variant &dither, const Variant &num_colors) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[569]);
    }
    return call(_fn, {image, dither, num_colors});
}
Variant imagepalettetotruecolor(const GdImage &image) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[570]);
    }
    return call(_fn, {image.getObject()});
}
Variant imagepalettetotruecolor(const Variant &image) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[570]);
    }
    return call(_fn, {image});
}
Variant imagecolormatch(const GdImage &image1, const GdImage &image2) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[571]);
    }
    return call(_fn, {image1.getObject(), image2.getObject()});
}
Variant imagecolormatch(const Variant &image1, const Variant &image2) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[571]);
    }
    return call(_fn, {image1, image2});
}
Variant imagesetthickness(const GdImage &image, const Variant &thickness) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[572]);
    }
    return call(_fn, {image.getObject(), thickness});
}
Variant imagesetthickness(const Variant &image, const Variant &thickness) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[572]);
    }
    return call(_fn, {image, thickness});
}
Variant imagefilledellipse(const GdImage &image,
                           const Variant &center_x,
                           const Variant &center_y,
                           const Variant &width,
                           const Variant &height,
                           const Variant &color) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[573]);
    }
    return call(_fn, {image.getObject(), center_x, center_y, width, height, color});
}
Variant imagefilledellipse(const Variant &image,
                           const Variant &center_x,
                           const Variant &center_y,
                           const Variant &width,
                           const Variant &height,
                           const Variant &color) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[573]);
    }
    return call(_fn, {image, center_x, center_y, width, height, color});
}
Variant imagefilledarc(const GdImage &image,
                       const Variant &center_x,
                       const Variant &center_y,
                       const Variant &width,
                       const Variant &height,
                       const Variant &start_angle,
                       const Variant &end_angle,
                       const Variant &color,
                       const Variant &style) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[574]);
    }
    return call(_fn, {image.getObject(), center_x, center_y, width, height, start_angle, end_angle, color, style});
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
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[574]);
    }
    return call(_fn, {image, center_x, center_y, width, height, start_angle, end_angle, color, style});
}
Variant imagealphablending(const GdImage &image, const Variant &enable) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[575]);
    }
    return call(_fn, {image.getObject(), enable});
}
Variant imagealphablending(const Variant &image, const Variant &enable) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[575]);
    }
    return call(_fn, {image, enable});
}
Variant imagesavealpha(const GdImage &image, const Variant &enable) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[576]);
    }
    return call(_fn, {image.getObject(), enable});
}
Variant imagesavealpha(const Variant &image, const Variant &enable) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[576]);
    }
    return call(_fn, {image, enable});
}
Variant imagelayereffect(const GdImage &image, const Variant &effect) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[577]);
    }
    return call(_fn, {image.getObject(), effect});
}
Variant imagelayereffect(const Variant &image, const Variant &effect) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[577]);
    }
    return call(_fn, {image, effect});
}
Variant imagecolorallocatealpha(
    const GdImage &image, const Variant &red, const Variant &green, const Variant &blue, const Variant &alpha) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[578]);
    }
    return call(_fn, {image.getObject(), red, green, blue, alpha});
}
Variant imagecolorallocatealpha(
    const Variant &image, const Variant &red, const Variant &green, const Variant &blue, const Variant &alpha) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[578]);
    }
    return call(_fn, {image, red, green, blue, alpha});
}
Variant imagecolorresolvealpha(
    const GdImage &image, const Variant &red, const Variant &green, const Variant &blue, const Variant &alpha) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[579]);
    }
    return call(_fn, {image.getObject(), red, green, blue, alpha});
}
Variant imagecolorresolvealpha(
    const Variant &image, const Variant &red, const Variant &green, const Variant &blue, const Variant &alpha) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[579]);
    }
    return call(_fn, {image, red, green, blue, alpha});
}
Variant imagecolorclosestalpha(
    const GdImage &image, const Variant &red, const Variant &green, const Variant &blue, const Variant &alpha) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[580]);
    }
    return call(_fn, {image.getObject(), red, green, blue, alpha});
}
Variant imagecolorclosestalpha(
    const Variant &image, const Variant &red, const Variant &green, const Variant &blue, const Variant &alpha) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[580]);
    }
    return call(_fn, {image, red, green, blue, alpha});
}
Variant imagecolorexactalpha(
    const GdImage &image, const Variant &red, const Variant &green, const Variant &blue, const Variant &alpha) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[581]);
    }
    return call(_fn, {image.getObject(), red, green, blue, alpha});
}
Variant imagecolorexactalpha(
    const Variant &image, const Variant &red, const Variant &green, const Variant &blue, const Variant &alpha) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[581]);
    }
    return call(_fn, {image, red, green, blue, alpha});
}
Variant imagecopyresampled(const GdImage &dst_image,
                           const GdImage &src_image,
                           const Variant &dst_x,
                           const Variant &dst_y,
                           const Variant &src_x,
                           const Variant &src_y,
                           const Variant &dst_width,
                           const Variant &dst_height,
                           const Variant &src_width,
                           const Variant &src_height) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[582]);
    }
    return call(_fn,
                {dst_image.getObject(),
                 src_image.getObject(),
                 dst_x,
                 dst_y,
                 src_x,
                 src_y,
                 dst_width,
                 dst_height,
                 src_width,
                 src_height});
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
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[582]);
    }
    return call(_fn, {dst_image, src_image, dst_x, dst_y, src_x, src_y, dst_width, dst_height, src_width, src_height});
}
GdImage imagerotate(const GdImage &image, const Variant &angle, const Variant &background_color) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[583]);
    }
    auto _rv = call(_fn, {image.getObject(), angle, background_color});
    if (!_rv.toBool()) {
        throwException(String("RuntimeException"), "imagerotate() returned false");
    }
    return GdImage(Object(std::move(_rv)));
}
Variant imagerotate(const Variant &image, const Variant &angle, const Variant &background_color) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[583]);
    }
    return call(_fn, {image, angle, background_color});
}
Variant imagesettile(const GdImage &image, const GdImage &tile) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[584]);
    }
    return call(_fn, {image.getObject(), tile.getObject()});
}
Variant imagesettile(const Variant &image, const Variant &tile) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[584]);
    }
    return call(_fn, {image, tile});
}
Variant imagesetbrush(const GdImage &image, const GdImage &brush) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[585]);
    }
    return call(_fn, {image.getObject(), brush.getObject()});
}
Variant imagesetbrush(const Variant &image, const Variant &brush) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[585]);
    }
    return call(_fn, {image, brush});
}
GdImage imagecreate(const Variant &width, const Variant &height) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[586]);
    }
    auto _rv = call(_fn, {width, height});
    if (!_rv.toBool()) {
        throwException(String("RuntimeException"), "imagecreate() returned false");
    }
    return GdImage(Object(std::move(_rv)));
}
Variant imagetypes() {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[587]);
    }
    return call(_fn, {});
}
GdImage imagecreatefromstring(const Variant &data) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[588]);
    }
    auto _rv = call(_fn, {data});
    if (!_rv.toBool()) {
        throwException(String("RuntimeException"), "imagecreatefromstring() returned false");
    }
    return GdImage(Object(std::move(_rv)));
}
GdImage imagecreatefromgif(const Variant &filename) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[589]);
    }
    auto _rv = call(_fn, {filename});
    if (!_rv.toBool()) {
        throwException(String("RuntimeException"), "imagecreatefromgif() returned false");
    }
    return GdImage(Object(std::move(_rv)));
}
GdImage imagecreatefromjpeg(const Variant &filename) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[590]);
    }
    auto _rv = call(_fn, {filename});
    if (!_rv.toBool()) {
        throwException(String("RuntimeException"), "imagecreatefromjpeg() returned false");
    }
    return GdImage(Object(std::move(_rv)));
}
GdImage imagecreatefrompng(const Variant &filename) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[591]);
    }
    auto _rv = call(_fn, {filename});
    if (!_rv.toBool()) {
        throwException(String("RuntimeException"), "imagecreatefrompng() returned false");
    }
    return GdImage(Object(std::move(_rv)));
}
GdImage imagecreatefromwebp(const Variant &filename) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[592]);
    }
    auto _rv = call(_fn, {filename});
    if (!_rv.toBool()) {
        throwException(String("RuntimeException"), "imagecreatefromwebp() returned false");
    }
    return GdImage(Object(std::move(_rv)));
}
GdImage imagecreatefromxbm(const Variant &filename) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[593]);
    }
    auto _rv = call(_fn, {filename});
    if (!_rv.toBool()) {
        throwException(String("RuntimeException"), "imagecreatefromxbm() returned false");
    }
    return GdImage(Object(std::move(_rv)));
}
GdImage imagecreatefromwbmp(const Variant &filename) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[594]);
    }
    auto _rv = call(_fn, {filename});
    if (!_rv.toBool()) {
        throwException(String("RuntimeException"), "imagecreatefromwbmp() returned false");
    }
    return GdImage(Object(std::move(_rv)));
}
GdImage imagecreatefromgd(const Variant &filename) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[595]);
    }
    auto _rv = call(_fn, {filename});
    if (!_rv.toBool()) {
        throwException(String("RuntimeException"), "imagecreatefromgd() returned false");
    }
    return GdImage(Object(std::move(_rv)));
}
GdImage imagecreatefromgd2(const Variant &filename) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[596]);
    }
    auto _rv = call(_fn, {filename});
    if (!_rv.toBool()) {
        throwException(String("RuntimeException"), "imagecreatefromgd2() returned false");
    }
    return GdImage(Object(std::move(_rv)));
}
GdImage imagecreatefromgd2part(
    const Variant &filename, const Variant &x, const Variant &y, const Variant &width, const Variant &height) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[597]);
    }
    auto _rv = call(_fn, {filename, x, y, width, height});
    if (!_rv.toBool()) {
        throwException(String("RuntimeException"), "imagecreatefromgd2part() returned false");
    }
    return GdImage(Object(std::move(_rv)));
}
GdImage imagecreatefrombmp(const Variant &filename) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[598]);
    }
    auto _rv = call(_fn, {filename});
    if (!_rv.toBool()) {
        throwException(String("RuntimeException"), "imagecreatefrombmp() returned false");
    }
    return GdImage(Object(std::move(_rv)));
}
GdImage imagecreatefromtga(const Variant &filename) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[599]);
    }
    auto _rv = call(_fn, {filename});
    if (!_rv.toBool()) {
        throwException(String("RuntimeException"), "imagecreatefromtga() returned false");
    }
    return GdImage(Object(std::move(_rv)));
}
Variant imagexbm(const GdImage &image, const Variant &filename, const Variant &foreground_color) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[600]);
    }
    return call(_fn, {image.getObject(), filename, foreground_color});
}
Variant imagexbm(const Variant &image, const Variant &filename, const Variant &foreground_color) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[600]);
    }
    return call(_fn, {image, filename, foreground_color});
}
Variant imagegif(const GdImage &image, const Variant &file) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[601]);
    }
    return call(_fn, {image.getObject(), file});
}
Variant imagegif(const Variant &image, const Variant &file) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[601]);
    }
    return call(_fn, {image, file});
}
Variant imagepng(const GdImage &image, const Variant &file, const Variant &quality, const Variant &filters) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[602]);
    }
    return call(_fn, {image.getObject(), file, quality, filters});
}
Variant imagepng(const Variant &image, const Variant &file, const Variant &quality, const Variant &filters) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[602]);
    }
    return call(_fn, {image, file, quality, filters});
}
Variant imagewebp(const GdImage &image, const Variant &file, const Variant &quality) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[603]);
    }
    return call(_fn, {image.getObject(), file, quality});
}
Variant imagewebp(const Variant &image, const Variant &file, const Variant &quality) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[603]);
    }
    return call(_fn, {image, file, quality});
}
Variant imagejpeg(const GdImage &image, const Variant &file, const Variant &quality) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[604]);
    }
    return call(_fn, {image.getObject(), file, quality});
}
Variant imagejpeg(const Variant &image, const Variant &file, const Variant &quality) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[604]);
    }
    return call(_fn, {image, file, quality});
}
Variant imagewbmp(const GdImage &image, const Variant &file, const Variant &foreground_color) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[605]);
    }
    return call(_fn, {image.getObject(), file, foreground_color});
}
Variant imagewbmp(const Variant &image, const Variant &file, const Variant &foreground_color) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[605]);
    }
    return call(_fn, {image, file, foreground_color});
}
Variant imagegd(const GdImage &image, const Variant &file) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[606]);
    }
    return call(_fn, {image.getObject(), file});
}
Variant imagegd(const Variant &image, const Variant &file) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[606]);
    }
    return call(_fn, {image, file});
}
Variant imagegd2(const GdImage &image, const Variant &file, const Variant &chunk_size, const Variant &mode) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[607]);
    }
    return call(_fn, {image.getObject(), file, chunk_size, mode});
}
Variant imagegd2(const Variant &image, const Variant &file, const Variant &chunk_size, const Variant &mode) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[607]);
    }
    return call(_fn, {image, file, chunk_size, mode});
}
Variant imagebmp(const GdImage &image, const Variant &file, const Variant &compressed) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[608]);
    }
    return call(_fn, {image.getObject(), file, compressed});
}
Variant imagebmp(const Variant &image, const Variant &file, const Variant &compressed) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[608]);
    }
    return call(_fn, {image, file, compressed});
}
Variant imagedestroy(const GdImage &image) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[609]);
    }
    return call(_fn, {image.getObject()});
}
Variant imagedestroy(const Variant &image) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[609]);
    }
    return call(_fn, {image});
}
Variant imagecolorallocate(const GdImage &image, const Variant &red, const Variant &green, const Variant &blue) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[610]);
    }
    return call(_fn, {image.getObject(), red, green, blue});
}
Variant imagecolorallocate(const Variant &image, const Variant &red, const Variant &green, const Variant &blue) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[610]);
    }
    return call(_fn, {image, red, green, blue});
}
Variant imagepalettecopy(const GdImage &dst, const GdImage &src) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[611]);
    }
    return call(_fn, {dst.getObject(), src.getObject()});
}
Variant imagepalettecopy(const Variant &dst, const Variant &src) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[611]);
    }
    return call(_fn, {dst, src});
}
Variant imagecolorat(const GdImage &image, const Variant &x, const Variant &y) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[612]);
    }
    return call(_fn, {image.getObject(), x, y});
}
Variant imagecolorat(const Variant &image, const Variant &x, const Variant &y) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[612]);
    }
    return call(_fn, {image, x, y});
}
Variant imagecolorclosest(const GdImage &image, const Variant &red, const Variant &green, const Variant &blue) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[613]);
    }
    return call(_fn, {image.getObject(), red, green, blue});
}
Variant imagecolorclosest(const Variant &image, const Variant &red, const Variant &green, const Variant &blue) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[613]);
    }
    return call(_fn, {image, red, green, blue});
}
Variant imagecolorclosesthwb(const GdImage &image, const Variant &red, const Variant &green, const Variant &blue) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[614]);
    }
    return call(_fn, {image.getObject(), red, green, blue});
}
Variant imagecolorclosesthwb(const Variant &image, const Variant &red, const Variant &green, const Variant &blue) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[614]);
    }
    return call(_fn, {image, red, green, blue});
}
Variant imagecolordeallocate(const GdImage &image, const Variant &color) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[615]);
    }
    return call(_fn, {image.getObject(), color});
}
Variant imagecolordeallocate(const Variant &image, const Variant &color) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[615]);
    }
    return call(_fn, {image, color});
}
Variant imagecolorresolve(const GdImage &image, const Variant &red, const Variant &green, const Variant &blue) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[616]);
    }
    return call(_fn, {image.getObject(), red, green, blue});
}
Variant imagecolorresolve(const Variant &image, const Variant &red, const Variant &green, const Variant &blue) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[616]);
    }
    return call(_fn, {image, red, green, blue});
}
Variant imagecolorexact(const GdImage &image, const Variant &red, const Variant &green, const Variant &blue) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[617]);
    }
    return call(_fn, {image.getObject(), red, green, blue});
}
Variant imagecolorexact(const Variant &image, const Variant &red, const Variant &green, const Variant &blue) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[617]);
    }
    return call(_fn, {image, red, green, blue});
}
Variant imagecolorset(const GdImage &image,
                      const Variant &color,
                      const Variant &red,
                      const Variant &green,
                      const Variant &blue,
                      const Variant &alpha) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[618]);
    }
    return call(_fn, {image.getObject(), color, red, green, blue, alpha});
}
Variant imagecolorset(const Variant &image,
                      const Variant &color,
                      const Variant &red,
                      const Variant &green,
                      const Variant &blue,
                      const Variant &alpha) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[618]);
    }
    return call(_fn, {image, color, red, green, blue, alpha});
}
Variant imagecolorsforindex(const GdImage &image, const Variant &color) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[619]);
    }
    return call(_fn, {image.getObject(), color});
}
Variant imagecolorsforindex(const Variant &image, const Variant &color) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[619]);
    }
    return call(_fn, {image, color});
}
Variant imagegammacorrect(const GdImage &image, const Variant &input_gamma, const Variant &output_gamma) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[620]);
    }
    return call(_fn, {image.getObject(), input_gamma, output_gamma});
}
Variant imagegammacorrect(const Variant &image, const Variant &input_gamma, const Variant &output_gamma) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[620]);
    }
    return call(_fn, {image, input_gamma, output_gamma});
}
Variant imagesetpixel(const GdImage &image, const Variant &x, const Variant &y, const Variant &color) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[621]);
    }
    return call(_fn, {image.getObject(), x, y, color});
}
Variant imagesetpixel(const Variant &image, const Variant &x, const Variant &y, const Variant &color) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[621]);
    }
    return call(_fn, {image, x, y, color});
}
Variant imageline(const GdImage &image,
                  const Variant &x1,
                  const Variant &y1,
                  const Variant &x2,
                  const Variant &y2,
                  const Variant &color) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[622]);
    }
    return call(_fn, {image.getObject(), x1, y1, x2, y2, color});
}
Variant imageline(const Variant &image,
                  const Variant &x1,
                  const Variant &y1,
                  const Variant &x2,
                  const Variant &y2,
                  const Variant &color) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[622]);
    }
    return call(_fn, {image, x1, y1, x2, y2, color});
}
Variant imagedashedline(const GdImage &image,
                        const Variant &x1,
                        const Variant &y1,
                        const Variant &x2,
                        const Variant &y2,
                        const Variant &color) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[623]);
    }
    return call(_fn, {image.getObject(), x1, y1, x2, y2, color});
}
Variant imagedashedline(const Variant &image,
                        const Variant &x1,
                        const Variant &y1,
                        const Variant &x2,
                        const Variant &y2,
                        const Variant &color) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[623]);
    }
    return call(_fn, {image, x1, y1, x2, y2, color});
}
Variant imagerectangle(const GdImage &image,
                       const Variant &x1,
                       const Variant &y1,
                       const Variant &x2,
                       const Variant &y2,
                       const Variant &color) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[624]);
    }
    return call(_fn, {image.getObject(), x1, y1, x2, y2, color});
}
Variant imagerectangle(const Variant &image,
                       const Variant &x1,
                       const Variant &y1,
                       const Variant &x2,
                       const Variant &y2,
                       const Variant &color) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[624]);
    }
    return call(_fn, {image, x1, y1, x2, y2, color});
}
Variant imagefilledrectangle(const GdImage &image,
                             const Variant &x1,
                             const Variant &y1,
                             const Variant &x2,
                             const Variant &y2,
                             const Variant &color) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[625]);
    }
    return call(_fn, {image.getObject(), x1, y1, x2, y2, color});
}
Variant imagefilledrectangle(const Variant &image,
                             const Variant &x1,
                             const Variant &y1,
                             const Variant &x2,
                             const Variant &y2,
                             const Variant &color) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[625]);
    }
    return call(_fn, {image, x1, y1, x2, y2, color});
}
Variant imagearc(const GdImage &image,
                 const Variant &center_x,
                 const Variant &center_y,
                 const Variant &width,
                 const Variant &height,
                 const Variant &start_angle,
                 const Variant &end_angle,
                 const Variant &color) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[626]);
    }
    return call(_fn, {image.getObject(), center_x, center_y, width, height, start_angle, end_angle, color});
}
Variant imagearc(const Variant &image,
                 const Variant &center_x,
                 const Variant &center_y,
                 const Variant &width,
                 const Variant &height,
                 const Variant &start_angle,
                 const Variant &end_angle,
                 const Variant &color) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[626]);
    }
    return call(_fn, {image, center_x, center_y, width, height, start_angle, end_angle, color});
}
Variant imageellipse(const GdImage &image,
                     const Variant &center_x,
                     const Variant &center_y,
                     const Variant &width,
                     const Variant &height,
                     const Variant &color) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[627]);
    }
    return call(_fn, {image.getObject(), center_x, center_y, width, height, color});
}
Variant imageellipse(const Variant &image,
                     const Variant &center_x,
                     const Variant &center_y,
                     const Variant &width,
                     const Variant &height,
                     const Variant &color) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[627]);
    }
    return call(_fn, {image, center_x, center_y, width, height, color});
}
Variant imagefilltoborder(
    const GdImage &image, const Variant &x, const Variant &y, const Variant &border_color, const Variant &color) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[628]);
    }
    return call(_fn, {image.getObject(), x, y, border_color, color});
}
Variant imagefilltoborder(
    const Variant &image, const Variant &x, const Variant &y, const Variant &border_color, const Variant &color) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[628]);
    }
    return call(_fn, {image, x, y, border_color, color});
}
Variant imagefill(const GdImage &image, const Variant &x, const Variant &y, const Variant &color) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[629]);
    }
    return call(_fn, {image.getObject(), x, y, color});
}
Variant imagefill(const Variant &image, const Variant &x, const Variant &y, const Variant &color) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[629]);
    }
    return call(_fn, {image, x, y, color});
}
Variant imagecolorstotal(const GdImage &image) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[630]);
    }
    return call(_fn, {image.getObject()});
}
Variant imagecolorstotal(const Variant &image) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[630]);
    }
    return call(_fn, {image});
}
Variant imagecolortransparent(const GdImage &image, const Variant &color) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[631]);
    }
    return call(_fn, {image.getObject(), color});
}
Variant imagecolortransparent(const Variant &image, const Variant &color) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[631]);
    }
    return call(_fn, {image, color});
}
Variant imageinterlace(const GdImage &image, const Variant &enable) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[632]);
    }
    return call(_fn, {image.getObject(), enable});
}
Variant imageinterlace(const Variant &image, const Variant &enable) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[632]);
    }
    return call(_fn, {image, enable});
}
Variant imagepolygon(const GdImage &image,
                     const Variant &points,
                     const Variant &num_points_or_color,
                     const Variant &color) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[633]);
    }
    return call(_fn, {image.getObject(), points, num_points_or_color, color});
}
Variant imagepolygon(const Variant &image,
                     const Variant &points,
                     const Variant &num_points_or_color,
                     const Variant &color) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[633]);
    }
    return call(_fn, {image, points, num_points_or_color, color});
}
Variant imageopenpolygon(const GdImage &image,
                         const Variant &points,
                         const Variant &num_points_or_color,
                         const Variant &color) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[634]);
    }
    return call(_fn, {image.getObject(), points, num_points_or_color, color});
}
Variant imageopenpolygon(const Variant &image,
                         const Variant &points,
                         const Variant &num_points_or_color,
                         const Variant &color) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[634]);
    }
    return call(_fn, {image, points, num_points_or_color, color});
}
Variant imagefilledpolygon(const GdImage &image,
                           const Variant &points,
                           const Variant &num_points_or_color,
                           const Variant &color) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[635]);
    }
    return call(_fn, {image.getObject(), points, num_points_or_color, color});
}
Variant imagefilledpolygon(const Variant &image,
                           const Variant &points,
                           const Variant &num_points_or_color,
                           const Variant &color) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[635]);
    }
    return call(_fn, {image, points, num_points_or_color, color});
}
Variant imagefontwidth(const Variant &font) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[636]);
    }
    return call(_fn, {font});
}
Variant imagefontheight(const Variant &font) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[637]);
    }
    return call(_fn, {font});
}
Variant imagechar(const GdImage &image,
                  const Variant &font,
                  const Variant &x,
                  const Variant &y,
                  const Variant &char_,
                  const Variant &color) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[638]);
    }
    return call(_fn, {image.getObject(), font, x, y, char_, color});
}
Variant imagechar(const Variant &image,
                  const Variant &font,
                  const Variant &x,
                  const Variant &y,
                  const Variant &char_,
                  const Variant &color) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[638]);
    }
    return call(_fn, {image, font, x, y, char_, color});
}
Variant imagecharup(const GdImage &image,
                    const Variant &font,
                    const Variant &x,
                    const Variant &y,
                    const Variant &char_,
                    const Variant &color) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[639]);
    }
    return call(_fn, {image.getObject(), font, x, y, char_, color});
}
Variant imagecharup(const Variant &image,
                    const Variant &font,
                    const Variant &x,
                    const Variant &y,
                    const Variant &char_,
                    const Variant &color) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[639]);
    }
    return call(_fn, {image, font, x, y, char_, color});
}
Variant imagestring(const GdImage &image,
                    const Variant &font,
                    const Variant &x,
                    const Variant &y,
                    const Variant &string,
                    const Variant &color) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[640]);
    }
    return call(_fn, {image.getObject(), font, x, y, string, color});
}
Variant imagestring(const Variant &image,
                    const Variant &font,
                    const Variant &x,
                    const Variant &y,
                    const Variant &string,
                    const Variant &color) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[640]);
    }
    return call(_fn, {image, font, x, y, string, color});
}
Variant imagestringup(const GdImage &image,
                      const Variant &font,
                      const Variant &x,
                      const Variant &y,
                      const Variant &string,
                      const Variant &color) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[641]);
    }
    return call(_fn, {image.getObject(), font, x, y, string, color});
}
Variant imagestringup(const Variant &image,
                      const Variant &font,
                      const Variant &x,
                      const Variant &y,
                      const Variant &string,
                      const Variant &color) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[641]);
    }
    return call(_fn, {image, font, x, y, string, color});
}
Variant imagecopy(const GdImage &dst_image,
                  const GdImage &src_image,
                  const Variant &dst_x,
                  const Variant &dst_y,
                  const Variant &src_x,
                  const Variant &src_y,
                  const Variant &src_width,
                  const Variant &src_height) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[642]);
    }
    return call(_fn, {dst_image.getObject(), src_image.getObject(), dst_x, dst_y, src_x, src_y, src_width, src_height});
}
Variant imagecopy(const Variant &dst_image,
                  const Variant &src_image,
                  const Variant &dst_x,
                  const Variant &dst_y,
                  const Variant &src_x,
                  const Variant &src_y,
                  const Variant &src_width,
                  const Variant &src_height) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[642]);
    }
    return call(_fn, {dst_image, src_image, dst_x, dst_y, src_x, src_y, src_width, src_height});
}
Variant imagecopymerge(const GdImage &dst_image,
                       const GdImage &src_image,
                       const Variant &dst_x,
                       const Variant &dst_y,
                       const Variant &src_x,
                       const Variant &src_y,
                       const Variant &src_width,
                       const Variant &src_height,
                       const Variant &pct) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[643]);
    }
    return call(_fn,
                {dst_image.getObject(), src_image.getObject(), dst_x, dst_y, src_x, src_y, src_width, src_height, pct});
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
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[643]);
    }
    return call(_fn, {dst_image, src_image, dst_x, dst_y, src_x, src_y, src_width, src_height, pct});
}
Variant imagecopymergegray(const GdImage &dst_image,
                           const GdImage &src_image,
                           const Variant &dst_x,
                           const Variant &dst_y,
                           const Variant &src_x,
                           const Variant &src_y,
                           const Variant &src_width,
                           const Variant &src_height,
                           const Variant &pct) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[644]);
    }
    return call(_fn,
                {dst_image.getObject(), src_image.getObject(), dst_x, dst_y, src_x, src_y, src_width, src_height, pct});
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
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[644]);
    }
    return call(_fn, {dst_image, src_image, dst_x, dst_y, src_x, src_y, src_width, src_height, pct});
}
Variant imagecopyresized(const GdImage &dst_image,
                         const GdImage &src_image,
                         const Variant &dst_x,
                         const Variant &dst_y,
                         const Variant &src_x,
                         const Variant &src_y,
                         const Variant &dst_width,
                         const Variant &dst_height,
                         const Variant &src_width,
                         const Variant &src_height) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[645]);
    }
    return call(_fn,
                {dst_image.getObject(),
                 src_image.getObject(),
                 dst_x,
                 dst_y,
                 src_x,
                 src_y,
                 dst_width,
                 dst_height,
                 src_width,
                 src_height});
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
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[645]);
    }
    return call(_fn, {dst_image, src_image, dst_x, dst_y, src_x, src_y, dst_width, dst_height, src_width, src_height});
}
Variant imagesx(const GdImage &image) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[646]);
    }
    return call(_fn, {image.getObject()});
}
Variant imagesx(const Variant &image) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[646]);
    }
    return call(_fn, {image});
}
Variant imagesy(const GdImage &image) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[647]);
    }
    return call(_fn, {image.getObject()});
}
Variant imagesy(const Variant &image) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[647]);
    }
    return call(_fn, {image});
}
Variant imagesetclip(const GdImage &image, const Variant &x1, const Variant &y1, const Variant &x2, const Variant &y2) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[648]);
    }
    return call(_fn, {image.getObject(), x1, y1, x2, y2});
}
Variant imagesetclip(const Variant &image, const Variant &x1, const Variant &y1, const Variant &x2, const Variant &y2) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[648]);
    }
    return call(_fn, {image, x1, y1, x2, y2});
}
Variant imagegetclip(const GdImage &image) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[649]);
    }
    return call(_fn, {image.getObject()});
}
Variant imagegetclip(const Variant &image) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[649]);
    }
    return call(_fn, {image});
}
Variant imageconvolution(const GdImage &image, const Variant &matrix, const Variant &divisor, const Variant &offset) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[651]);
    }
    return call(_fn, {image.getObject(), matrix, divisor, offset});
}
Variant imageconvolution(const Variant &image, const Variant &matrix, const Variant &divisor, const Variant &offset) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[651]);
    }
    return call(_fn, {image, matrix, divisor, offset});
}
Variant imageflip(const GdImage &image, const Variant &mode) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[652]);
    }
    return call(_fn, {image.getObject(), mode});
}
Variant imageflip(const Variant &image, const Variant &mode) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[652]);
    }
    return call(_fn, {image, mode});
}
Variant imageantialias(const GdImage &image, const Variant &enable) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[653]);
    }
    return call(_fn, {image.getObject(), enable});
}
Variant imageantialias(const Variant &image, const Variant &enable) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[653]);
    }
    return call(_fn, {image, enable});
}
GdImage imagecrop(const GdImage &image, const Variant &rectangle) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[654]);
    }
    auto _rv = call(_fn, {image.getObject(), rectangle});
    if (!_rv.toBool()) {
        throwException(String("RuntimeException"), "imagecrop() returned false");
    }
    return GdImage(Object(std::move(_rv)));
}
Variant imagecrop(const Variant &image, const Variant &rectangle) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[654]);
    }
    return call(_fn, {image, rectangle});
}
GdImage imagecropauto(const GdImage &image, const Variant &mode, const Variant &threshold, const Variant &color) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[655]);
    }
    auto _rv = call(_fn, {image.getObject(), mode, threshold, color});
    if (!_rv.toBool()) {
        throwException(String("RuntimeException"), "imagecropauto() returned false");
    }
    return GdImage(Object(std::move(_rv)));
}
Variant imagecropauto(const Variant &image, const Variant &mode, const Variant &threshold, const Variant &color) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[655]);
    }
    return call(_fn, {image, mode, threshold, color});
}
GdImage imagescale(const GdImage &image, const Variant &width, const Variant &height, const Variant &mode) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[656]);
    }
    auto _rv = call(_fn, {image.getObject(), width, height, mode});
    if (!_rv.toBool()) {
        throwException(String("RuntimeException"), "imagescale() returned false");
    }
    return GdImage(Object(std::move(_rv)));
}
Variant imagescale(const Variant &image, const Variant &width, const Variant &height, const Variant &mode) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[656]);
    }
    return call(_fn, {image, width, height, mode});
}
GdImage imageaffine(const GdImage &image, const Variant &affine, const Variant &clip) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[657]);
    }
    auto _rv = call(_fn, {image.getObject(), affine, clip});
    if (!_rv.toBool()) {
        throwException(String("RuntimeException"), "imageaffine() returned false");
    }
    return GdImage(Object(std::move(_rv)));
}
Variant imageaffine(const Variant &image, const Variant &affine, const Variant &clip) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[657]);
    }
    return call(_fn, {image, affine, clip});
}
Variant imageaffinematrixget(const Variant &type, const Variant &options) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[658]);
    }
    return call(_fn, {type, options});
}
Variant imageaffinematrixconcat(const Variant &matrix1, const Variant &matrix2) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[659]);
    }
    return call(_fn, {matrix1, matrix2});
}
Variant imagegetinterpolation(const GdImage &image) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[660]);
    }
    return call(_fn, {image.getObject()});
}
Variant imagegetinterpolation(const Variant &image) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[660]);
    }
    return call(_fn, {image});
}
Variant imagesetinterpolation(const GdImage &image, const Variant &method) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[661]);
    }
    return call(_fn, {image.getObject(), method});
}
Variant imagesetinterpolation(const Variant &image, const Variant &method) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[661]);
    }
    return call(_fn, {image, method});
}
Variant imageresolution(const GdImage &image, const Variant &resolution_x, const Variant &resolution_y) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[662]);
    }
    return call(_fn, {image.getObject(), resolution_x, resolution_y});
}
Variant imageresolution(const Variant &image, const Variant &resolution_x, const Variant &resolution_y) {
    static THREAD_LOCAL zend_function *_fn = nullptr;
    if (UNEXPECTED(!_fn)) {
        _fn = getFunction(LITERAL_STRING[662]);
    }
    return call(_fn, {image, resolution_x, resolution_y});
}
}  // namespace php
