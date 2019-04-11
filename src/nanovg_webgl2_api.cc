#define NAPI_EXPERIMENTAL
#include "nanovg_webgl2_api.h"
#include "nanovg.h"
#define NANOVG_WEBGL2_IMPLEMENTATION
#include "nanovg_webgl2.h"

#include "napi_decoder.h"
#include "napi_encoder.h"

#define MAX_PAINT_NUMBER 65536

#include <ctime>
#include <cstdlib>
#include <vector>
#include <assert.h>

static NVGcontext* vg;

struct VideoFrameData {
  uint8_t* data;
  int width;
  int height;
  int64_t pts;
};

NVGpaint paints[MAX_PAINT_NUMBER];
std::vector<int> paints_box;

void InitializePaints() {
  for (int i = 0; i < MAX_PAINT_NUMBER; i ++)
    paints_box.push_back(i);
}

int AllocatePaint() {
  int idx = paints_box.back();
  paints_box.pop_back();
  return idx;
}

void FreePaint(int paint) {
  paints_box.push_back(paint);
}








// void nvgBeginFrame(NVGcontext* ctx, float windowWidth, float windowHeight, float devicePixelRatio);
napi_value __nvg_beginFrame(napi_env env, napi_callback_info cbinfo) {
  setNAPIenv(env);
  size_t argc = 3;
  napi_value nv[3];
  napi_get_cb_info(env, cbinfo, &argc, nv, 0, 0);

  double windowWidth, windowHeight, devicePixelRatio;
  napi_get_value_double(env, nv[0], &windowWidth);
  napi_get_value_double(env, nv[1], &windowHeight);
  napi_get_value_double(env, nv[2], &devicePixelRatio);

  nvgBeginFrame(vg, windowWidth, windowHeight, devicePixelRatio);
  return 0;
}

// void nvgCancelFrame(NVGcontext* ctx);

// void nvgEndFrame(NVGcontext* ctx);
napi_value __nvgEndFrame(napi_env env, napi_callback_info cbinfo) {
  setNAPIenv(env);

  nvgEndFrame(vg);
  return 0;
}

// void nvgGlobalCompositeOperation(NVGcontext* ctx, int op);
napi_value __nvg_globalCompositeOperation(napi_env env, napi_callback_info cbinfo) {
  setNAPIenv(env);
  size_t argc = 1;
  napi_value nv[1];
  napi_get_cb_info(env, cbinfo, &argc, nv, 0, 0);

  int op;
  napi_get_value_int32(env, nv[0], &op);

  nvgGlobalCompositeOperation(vg, op);
  return 0;
}

// void nvgGlobalCompositeBlendFunc(NVGcontext* ctx, int sfactor, int dfactor);
napi_value __nvg_globalCompositeBlendFunc(napi_env env, napi_callback_info cbinfo) {
  setNAPIenv(env);
  size_t argc = 2;
  napi_value nv[2];
  napi_get_cb_info(env, cbinfo, &argc, nv, 0, 0);

  int sfactor, dfactor;
  napi_get_value_int32(env, nv[0], &sfactor);
  napi_get_value_int32(env, nv[1], &dfactor);

  nvgGlobalCompositeBlendFunc(vg, sfactor, dfactor);
  return 0;
}

// void nvgGlobalCompositeBlendFuncSeparate(NVGcontext* ctx, int srcRGB, int dstRGB, int srcAlpha, int dstAlpha);
napi_value __nvg_globalCompositeBlendFuncSeparate(napi_env env, napi_callback_info cbinfo) {
  setNAPIenv(env);
  size_t argc = 4;
  napi_value nv[4];
  napi_get_cb_info(env, cbinfo, &argc, nv, 0, 0);

  int srcRGB, dstRGB, srcAlpha, dstAlpha;
  napi_get_value_int32(env, nv[0], &srcRGB);
  napi_get_value_int32(env, nv[1], &dstRGB);
  napi_get_value_int32(env, nv[2], &srcAlpha);
  napi_get_value_int32(env, nv[3], &dstAlpha);

  nvgGlobalCompositeBlendFuncSeparate(vg, srcRGB, dstRGB, srcAlpha, dstAlpha);
  return 0;
}

// void nvgBlendEquation(NVGcontext* ctx, int mode);
napi_value __nvg_blendEquation(napi_env env, napi_callback_info cbinfo) {
  setNAPIenv(env);
  size_t argc = 1;
  napi_value nv[1];
  napi_get_cb_info(env, cbinfo, &argc, nv, 0, 0);

  int mode;
  napi_get_value_int32(env, nv[0], &mode);

  nvgBlendEquation(vg, mode);
  return 0;
}

// void nvgBlendEquationSeparate(NVGcontext* ctx, int modeRGB, int modeAlpha);
napi_value __nvg_blendEquationSeparate(napi_env env, napi_callback_info cbinfo) {
  setNAPIenv(env);
  size_t argc = 2;
  napi_value nv[2];
  napi_get_cb_info(env, cbinfo, &argc, nv, 0, 0);

  int modeRGB, modeAlpha;
  napi_get_value_int32(env, nv[1], &modeRGB);
  napi_get_value_int32(env, nv[1], &modeAlpha);

  nvgBlendEquationSeparate(vg, modeRGB, modeAlpha);
  return 0;
}

// NVGcolor nvgRGB(unsigned char r, unsigned char g, unsigned char b);
// NVGcolor nvgRGBf(float r, float g, float b);NVGcolor nvgRGBA(unsigned char r, unsigned char g, unsigned char b, unsigned char a);
// NVGcolor nvgRGBAf(float r, float g, float b, float a);
// NVGcolor nvgLerpRGBA(NVGcolor c0, NVGcolor c1, float u);
// NVGcolor nvgTransRGBA(NVGcolor c0, unsigned char a);
// NVGcolor nvgTransRGBAf(NVGcolor c0, float a);
// NVGcolor nvgHSL(float h, float s, float l);
// NVGcolor nvgHSLA(float h, float s, float l, unsigned char a);
// void nvgSave(NVGcontext* ctx);
napi_value __nvgSave(napi_env env, napi_callback_info cbinfo) {
  setNAPIenv(env);

  nvgSave(vg);
  return 0;
}

// void nvgRestore(NVGcontext* ctx);
napi_value __nvgRestore(napi_env env, napi_callback_info cbinfo) {
  setNAPIenv(env);

  nvgRestore(vg);
  return 0;
}

// void nvgReset(NVGcontext* ctx);void nvgShapeAntiAlias(NVGcontext* ctx, int enabled);
// void nvgStrokeColor(NVGcontext* ctx, NVGcolor color);
napi_value __nvgStrokeColor(napi_env env, napi_callback_info cbinfo) {
  setNAPIenv(env);
  size_t argc = 4;
  napi_value nv[4];
  napi_get_cb_info(env, cbinfo, &argc, nv, 0, 0);

  int r, g, b, a;
  napi_get_value_int32(env, nv[0], &r);
  napi_get_value_int32(env, nv[1], &g);
  napi_get_value_int32(env, nv[2], &b);
  napi_get_value_int32(env, nv[3], &a);

  nvgStrokeColor(vg, nvgRGBA(r, g, b, a));
  return 0;
}

// void nvgStrokePaint(NVGcontext* ctx, NVGpaint paint);
// void nvgFillColor(NVGcontext* ctx, NVGcolor color);
napi_value __nvgFillColor(napi_env env, napi_callback_info cbinfo) {
  setNAPIenv(env);
  size_t argc = 4;
  napi_value nv[4];
  napi_get_cb_info(env, cbinfo, &argc, nv, 0, 0);

  int r, g, b, a;
  napi_get_value_int32(env, nv[0], &r);
  napi_get_value_int32(env, nv[1], &g);
  napi_get_value_int32(env, nv[2], &b);
  napi_get_value_int32(env, nv[3], &a);

  nvgFillColor(vg, nvgRGBA(r, g, b, a));
  return 0;
}

// void nvgFillPaint(NVGcontext* ctx, NVGpaint paint);
napi_value __nvg_fillPaint(napi_env env, napi_callback_info cbinfo) {
  setNAPIenv(env);
  size_t argc = 1;
  napi_value nv[1];
  napi_get_cb_info(env, cbinfo, &argc, nv, 0, 0);

  int paint_id;
  napi_get_value_int32(env, nv[0], &paint_id);
  NVGpaint& paint = paints[paint_id];

  nvgFillPaint(vg, paint);
  return 0;
}

// void nvgMiterLimit(NVGcontext* ctx, float limit);
// void nvgStrokeWidth(NVGcontext* ctx, float size);
napi_value __nvgStrokeWidth(napi_env env, napi_callback_info cbinfo) {
  setNAPIenv(env);
  size_t argc = 1;
  napi_value nv[1];
  napi_get_cb_info(env, cbinfo, &argc, nv, 0, 0);

  double v;
  napi_get_value_double(env, nv[0], &v);

  nvgStrokeWidth(vg, v);
  return 0;
}

// void nvgLineCap(NVGcontext* ctx, int cap);
// void nvgLineJoin(NVGcontext* ctx, int join);
// void nvgGlobalAlpha(NVGcontext* ctx, float alpha);
// void nvgResetTransform(NVGcontext* ctx);
// void nvgTransform(NVGcontext* ctx, float a, float b, float c, float d, float e, float f);
// void nvgTranslate(NVGcontext* ctx, float x, float y);
napi_value __nvg_translate(napi_env env, napi_callback_info cbinfo) {
  setNAPIenv(env);
  size_t argc = 2;
  napi_value nv[2];
  napi_get_cb_info(env, cbinfo, &argc, nv, 0, 0);

  double x, y;
  napi_get_value_double(env, nv[0], &x);
  napi_get_value_double(env, nv[1], &y);

  nvgTranslate(vg, x, y);
  return 0;
}

// void nvgRotate(NVGcontext* ctx, float angle);
napi_value __nvg_rotate(napi_env env, napi_callback_info cbinfo) {
  setNAPIenv(env);
  size_t argc = 1;
  napi_value nv[1];
  napi_get_cb_info(env, cbinfo, &argc, nv, 0, 0);

  double r;
  napi_get_value_double(env, nv[0], &r);

  nvgRotate(vg, r);
  return 0;
}

// void nvgSkewX(NVGcontext* ctx, float angle);
// void nvgSkewY(NVGcontext* ctx, float angle);
// void nvgScale(NVGcontext* ctx, float x, float y);
napi_value __nvg_scale(napi_env env, napi_callback_info cbinfo) {
  setNAPIenv(env);
  size_t argc = 2;
  napi_value nv[2];
  napi_get_cb_info(env, cbinfo, &argc, nv, 0, 0);

  double x, y;
  napi_get_value_double(env, nv[0], &x);
  napi_get_value_double(env, nv[1], &y);

  nvgScale(vg, x, y);
  return 0;
}

// void nvgCurrentTransform(NVGcontext* ctx, float* xform);
// void nvgTransformIdentity(float* dst);
// void nvgTransformTranslate(float* dst, float tx, float ty);
// void nvgTransformScale(float* dst, float sx, float sy);
// void nvgTransformRotate(float* dst, float a);
// void nvgTransformSkewX(float* dst, float a);
// void nvgTransformSkewY(float* dst, float a);
// void nvgTransformMultiply(float* dst, const float* src);
// void nvgTransformPremultiply(float* dst, const float* src);
// int nvgTransformInverse(float* dst, const float* src);
// void nvgTransformPoint(float* dstx, float* dsty, const float* xform, float srcx, float srcy);
// float nvgDegToRad(float deg);
// float nvgRadToDeg(float rad);
// int nvgCreateImage(NVGcontext* ctx, const char* filename, int imageFlags);
// int nvgCreateImageMem(NVGcontext* ctx, int imageFlags, unsigned char* data, int ndata);
// int nvgCreateImageRGBA(NVGcontext* ctx, int w, int h, int imageFlags, const unsigned char* data);
napi_value __nvg_createImageRGBA(napi_env env, napi_callback_info cbinfo) {
  setNAPIenv(env);
  size_t argc = 4;
  napi_value nv[4];
  napi_value* nvp = nv;
  napi_get_cb_info(env, cbinfo, &argc, nv, 0, 0);

  int w, h, flag;
  uint64_t uaddr;
  bool lossless;
  napi_get_value_int32(env, *nvp++, &w);
  napi_get_value_int32(env, *nvp++, &h);
  napi_get_value_int32(env, *nvp++, &flag);
  napi_get_value_bigint_uint64(env, *nvp++, &uaddr, &lossless);
  assert(lossless);

  uint8_t* ptr = reinterpret_cast<uint8_t*>(uaddr);
  VideoFrameData* data = reinterpret_cast<VideoFrameData*>(ptr);

  int image = nvgCreateImageRGBA2(vg, w, h, flag, (unsigned char*)data->data);
  return napi_encoder<int32_t>::encode(env, image);
}

// int nvgCreateImageRGBA2(NVGcontext* ctx, int w, int h, int imageFlags, const unsigned char* data);
// void nvgUpdateImage(NVGcontext* ctx, int image, const unsigned char* data);
// void nvgImageSize(NVGcontext* ctx, int image, int* w, int* h);
// void nvgDeleteImage(NVGcontext* ctx, int image);
napi_value __nvg_deleteImage(napi_env env, napi_callback_info cbinfo) {
  setNAPIenv(env);
  size_t argc = 1;
  napi_value nv[1];
  napi_value* nvp = nv;
  napi_get_cb_info(env, cbinfo, &argc, nv, 0, 0);
  
  int image;
  napi_get_value_int32(env, *nvp++, &image);
  
  nvgDeleteImage(vg, image);
  return nullptr;
}

// NVGpaint nvgLinearGradient(NVGcontext* ctx, float sx, float sy, float ex, float ey,
//                NVGcolor icol, NVGcolor ocol);
// NVGpaint nvgBoxGradient(NVGcontext* ctx, float x, float y, float w, float h,
//             float r, float f, NVGcolor icol, NVGcolor ocol);
// NVGpaint nvgRadialGradient(NVGcontext* ctx, float cx, float cy, float inr, float outr,
//                NVGcolor icol, NVGcolor ocol);
// NVGpaint nvgImagePattern(NVGcontext* ctx, float ox, float oy, float ex, float ey,
//              float angle, int image, float alpha);
napi_value __nvg_imagePattern(napi_env env, napi_callback_info cbinfo) {
  setNAPIenv(env);
  size_t argc = 7;
  napi_value nv[7];
  napi_value* nvp = nv;
  napi_get_cb_info(env, cbinfo, &argc, nv, 0, 0);

  double ox, oy, ex, ey, angle, alpha;
  int image;
  napi_get_value_double(env, *nvp++, &ox);
  napi_get_value_double(env, *nvp++, &oy);
  napi_get_value_double(env, *nvp++, &ex);
  napi_get_value_double(env, *nvp++, &ey);
  napi_get_value_double(env, *nvp++, &angle);
  napi_get_value_int32(env, *nvp++, &image);
  napi_get_value_double(env, *nvp++, &alpha);

  int paint = AllocatePaint();
  paints[paint] = nvgImagePattern(vg, ox, oy, ex, ey, angle, image, alpha);

  return napi_encoder<int32_t>::encode(env, paint);
}

// void nvgScissor(NVGcontext* ctx, float x, float y, float w, float h);
// void nvgIntersectScissor(NVGcontext* ctx, float x, float y, float w, float h);
// void nvgResetScissor(NVGcontext* ctx);
// void nvgBeginPath(NVGcontext* ctx);
napi_value __nvgBeginPath(napi_env env, napi_callback_info cbinfo) {
  setNAPIenv(env);

  nvgBeginPath(vg);
  return 0;
}

// void nvgMoveTo(NVGcontext* ctx, float x, float y);
napi_value __nvgMoveTo(napi_env env, napi_callback_info cbinfo) {
  setNAPIenv(env);
  size_t argc = 2;
  napi_value nv[2];
  napi_get_cb_info(env, cbinfo, &argc, nv, 0, 0);

  double x, y;
  napi_get_value_double(env, nv[0], &x);
  napi_get_value_double(env, nv[1], &y);

  nvgMoveTo(vg, x, y);
  return 0;
}

// void nvgLineTo(NVGcontext* ctx, float x, float y);
napi_value __nvgLineTo(napi_env env, napi_callback_info cbinfo) {
  setNAPIenv(env);
  size_t argc = 2;
  napi_value nv[2];
  napi_get_cb_info(env, cbinfo, &argc, nv, 0, 0);

  double x, y;
  napi_get_value_double(env, nv[0], &x);
  napi_get_value_double(env, nv[1], &y);

  nvgLineTo(vg, x, y);
  return 0;
}

// void nvgBezierTo(NVGcontext* ctx, float c1x, float c1y, float c2x, float c2y, float x, float y);
// void nvgQuadTo(NVGcontext* ctx, float cx, float cy, float x, float y);
// void nvgArcTo(NVGcontext* ctx, float x1, float y1, float x2, float y2, float radius);
// void nvgClosePath(NVGcontext* ctx);
napi_value __nvgClosePath(napi_env env, napi_callback_info cbinfo) {
  setNAPIenv(env);

  nvgClosePath(vg);
  return 0;
}

// void nvgPathWinding(NVGcontext* ctx, int dir);
// void nvgArc(NVGcontext* ctx, float cx, float cy, float r, float a0, float a1, int dir);
// void nvgRect(NVGcontext* ctx, float x, float y, float w, float h);
// void nvgRoundedRect(NVGcontext* ctx, float x, float y, float w, float h, float r);
// void nvgRoundedRectVarying(NVGcontext* ctx, float x, float y, float w, float h, float radTopLeft, float radTopRight, float radBottomRight, float radBottomLeft);
// void nvgEllipse(NVGcontext* ctx, float cx, float cy, float rx, float ry);
// void nvgCircle(NVGcontext* ctx, float cx, float cy, float r);
// void nvgFill(NVGcontext* ctx);
napi_value __nvgFill(napi_env env, napi_callback_info cbinfo) {
  setNAPIenv(env);

  nvgFill(vg);
  return 0;
}

// void nvgStroke(NVGcontext* ctx);
napi_value __nvgStroke(napi_env env, napi_callback_info cbinfo) {
  setNAPIenv(env);

  nvgStroke(vg);
  return 0;
}

// int nvgCreateFont(NVGcontext* ctx, const char* name, const char* filename);
// int nvgCreateFontMem(NVGcontext* ctx, const char* name, unsigned char* data, int ndata, int freeData);
// int nvgFindFont(NVGcontext* ctx, const char* name);
// int nvgAddFallbackFontId(NVGcontext* ctx, int baseFont, int fallbackFont);
// int nvgAddFallbackFont(NVGcontext* ctx, const char* baseFont, const char* fallbackFont);
// void nvgFontSize(NVGcontext* ctx, float size);
// void nvgFontBlur(NVGcontext* ctx, float blur);
// void nvgTextLetterSpacing(NVGcontext* ctx, float spacing);
// void nvgTextLineHeight(NVGcontext* ctx, float lineHeight);
// void nvgTextAlign(NVGcontext* ctx, int align);
// void nvgFontFaceId(NVGcontext* ctx, int font);
// void nvgFontFace(NVGcontext* ctx, const char* font);
// float nvgText(NVGcontext* ctx, float x, float y, const char* string, const char* end);
// void nvgTextBox(NVGcontext* ctx, float x, float y, float breakRowWidth, const char* string, const char* end);
// float nvgTextBounds(NVGcontext* ctx, float x, float y, const char* string, const char* end, float* bounds);
// void nvgTextBoxBounds(NVGcontext* ctx, float x, float y, float breakRowWidth, const char* string, const char* end, float* bounds);
// int nvgTextGlyphPositions(NVGcontext* ctx, float x, float y, const char* string, const char* end, NVGglyphPosition* positions, int maxPositions);
// void nvgTextMetrics(NVGcontext* ctx, float* ascender, float* descender, float* lineh);
// int nvgTextBreakLines(NVGcontext* ctx, const char* string, const char* end, float breakRowWidth, NVGtextRow* rows, int maxRows);




napi_value __nvg_freePaint(napi_env env, napi_callback_info cbinfo) {
  setNAPIenv(env);
  size_t argc = 1;
  napi_value nv[1];
  napi_value* nvp = nv;
  napi_get_cb_info(env, cbinfo, &argc, nv, 0, 0);
  
  int paint;
  napi_get_value_int32(env, *nvp++, &paint);
  
  FreePaint(paint);
  return nullptr;
}


#define DefineAPI(name) \
    napi_value nvg_##name; \
    napi_create_function(env, #name, NAPI_AUTO_LENGTH, __nvg_##name, NULL, &nvg_##name); \
    napi_set_named_property(env, handle, #name, nvg_##name);

VideoFrameData frame;

int random(int min, int max) //range : [min, max)
{
   static bool first = true;
   if (first) 
   {  
      srand( time(NULL) ); //seeding for the first time only!
      first = false;
   }
   return min + rand() % (( max + 1 ) - min);
}

float random() //range : [min, max)
{
   return rand();
}

napi_value __nanovg_webgl2_init(napi_env env, napi_callback_info cbinfo) {
  setNAPIenv(env);

  size_t argc = 1;
  napi_value nv[1];
  napi_get_cb_info(env, cbinfo, &argc, nv, 0, 0);

  napi_value gl = nv[0];
  __webgl_context = __napi_create_ref(gl);

  __nanovg_webgl2_register_functions(env, gl);

  vg = nvgCreateWebGL2(NVG_ANTIALIAS | NVG_STENCIL_STROKES | NVG_DEBUG);

  napi_value handle;
  napi_create_object(env, &handle);

  DefineAPI(translate);
  DefineAPI(rotate);
  DefineAPI(scale);

  // void nvgBeginFrame(NVGcontext* ctx, float windowWidth, float windowHeight, float devicePixelRatio);
  DefineAPI(beginFrame);
  // void nvgCancelFrame(NVGcontext* ctx);
  // void nvgEndFrame(NVGcontext* ctx);
  // void nvgGlobalCompositeOperation(NVGcontext* ctx, int op);
  DefineAPI(globalCompositeOperation);
  // void nvgGlobalCompositeBlendFunc(NVGcontext* ctx, int sfactor, int dfactor);
  DefineAPI(globalCompositeBlendFunc);
  // void nvgGlobalCompositeBlendFuncSeparate(NVGcontext* ctx, int srcRGB, int dstRGB, int srcAlpha, int dstAlpha);
  DefineAPI(globalCompositeBlendFuncSeparate);
  // void nvgBlendEquation(NVGcontext* ctx, int mode);
  DefineAPI(blendEquation);
  // void nvgBlendEquationSeparate(NVGcontext* ctx, int modeRGB, int modeAlpha);
  DefineAPI(blendEquationSeparate);
  // NVGcolor nvgRGB(unsigned char r, unsigned char g, unsigned char b);
  // NVGcolor nvgRGBf(float r, float g, float b);
  // NVGcolor nvgRGBA(unsigned char r, unsigned char g, unsigned char b, unsigned char a);
  // NVGcolor nvgRGBAf(float r, float g, float b, float a);
  // NVGcolor nvgLerpRGBA(NVGcolor c0, NVGcolor c1, float u);
  // NVGcolor nvgTransRGBA(NVGcolor c0, unsigned char a);
  // NVGcolor nvgTransRGBAf(NVGcolor c0, float a);
  // NVGcolor nvgHSL(float h, float s, float l);
  // NVGcolor nvgHSLA(float h, float s, float l, unsigned char a);
  // void nvgSave(NVGcontext* ctx);
  // void nvgRestore(NVGcontext* ctx);
  // void nvgReset(NVGcontext* ctx);
  // void nvgShapeAntiAlias(NVGcontext* ctx, int enabled);
  // void nvgStrokeColor(NVGcontext* ctx, NVGcolor color);
  // void nvgStrokePaint(NVGcontext* ctx, NVGpaint paint);
  // void nvgFillColor(NVGcontext* ctx, NVGcolor color);
  // void nvgFillPaint(NVGcontext* ctx, NVGpaint paint);
  // void nvgMiterLimit(NVGcontext* ctx, float limit);
  // void nvgStrokeWidth(NVGcontext* ctx, float size);
  // void nvgLineCap(NVGcontext* ctx, int cap);
  // void nvgLineJoin(NVGcontext* ctx, int join);
  // void nvgGlobalAlpha(NVGcontext* ctx, float alpha);
  // void nvgResetTransform(NVGcontext* ctx);
  // void nvgTransform(NVGcontext* ctx, float a, float b, float c, float d, float e, float f);
  // void nvgTranslate(NVGcontext* ctx, float x, float y);
  // void nvgRotate(NVGcontext* ctx, float angle);
  // void nvgSkewX(NVGcontext* ctx, float angle);
  // void nvgSkewY(NVGcontext* ctx, float angle);
  // void nvgScale(NVGcontext* ctx, float x, float y);
  // void nvgCurrentTransform(NVGcontext* ctx, float* xform);
  // void nvgTransformIdentity(float* dst);
  // void nvgTransformTranslate(float* dst, float tx, float ty);
  // void nvgTransformScale(float* dst, float sx, float sy);
  // void nvgTransformRotate(float* dst, float a);
  // void nvgTransformSkewX(float* dst, float a);
  // void nvgTransformSkewY(float* dst, float a);
  // void nvgTransformMultiply(float* dst, const float* src);
  // void nvgTransformPremultiply(float* dst, const float* src);
  // int nvgTransformInverse(float* dst, const float* src);
  // void nvgTransformPoint(float* dstx, float* dsty, const float* xform, float srcx, float srcy);
  // float nvgDegToRad(float deg);
  // float nvgRadToDeg(float rad);
  // int nvgCreateImage(NVGcontext* ctx, const char* filename, int imageFlags);
  // int nvgCreateImageMem(NVGcontext* ctx, int imageFlags, unsigned char* data, int ndata);
  // int nvgCreateImageRGBA(NVGcontext* ctx, int w, int h, int imageFlags, const unsigned char* data);
  // int nvgCreateImageRGBA2(NVGcontext* ctx, int w, int h, int imageFlags, const unsigned char* data);
  // void nvgUpdateImage(NVGcontext* ctx, int image, const unsigned char* data);
  // void nvgImageSize(NVGcontext* ctx, int image, int* w, int* h);
  // void nvgDeleteImage(NVGcontext* ctx, int image);
  // NVGpaint nvgLinearGradient(NVGcontext* ctx, float sx, float sy, float ex, float ey,
  //               NVGcolor icol, NVGcolor ocol);
  // NVGpaint nvgBoxGradient(NVGcontext* ctx, float x, float y, float w, float h,
  //           float r, float f, NVGcolor icol, NVGcolor ocol);
  // NVGpaint nvgRadialGradient(NVGcontext* ctx, float cx, float cy, float inr, float outr,
  //               NVGcolor icol, NVGcolor ocol);
  // NVGpaint nvgImagePattern(NVGcontext* ctx, float ox, float oy, float ex, float ey,
  //             float angle, int image, float alpha);void nvgScissor(NVGcontext* ctx, float x, float y, float w, float h);
  // void nvgIntersectScissor(NVGcontext* ctx, float x, float y, float w, float h);
  // void nvgResetScissor(NVGcontext* ctx);void nvgBeginPath(NVGcontext* ctx);
  // void nvgMoveTo(NVGcontext* ctx, float x, float y);
  // void nvgLineTo(NVGcontext* ctx, float x, float y);
  // void nvgBezierTo(NVGcontext* ctx, float c1x, float c1y, float c2x, float c2y, float x, float y);
  // void nvgQuadTo(NVGcontext* ctx, float cx, float cy, float x, float y);
  // void nvgArcTo(NVGcontext* ctx, float x1, float y1, float x2, float y2, float radius);
  // void nvgClosePath(NVGcontext* ctx);
  // void nvgPathWinding(NVGcontext* ctx, int dir);
  // void nvgArc(NVGcontext* ctx, float cx, float cy, float r, float a0, float a1, int dir);
  // void nvgRect(NVGcontext* ctx, float x, float y, float w, float h);
  // void nvgRoundedRect(NVGcontext* ctx, float x, float y, float w, float h, float r);
  // void nvgRoundedRectVarying(NVGcontext* ctx, float x, float y, float w, float h, float radTopLeft, float radTopRight, float radBottomRight, float radBottomLeft);
  // void nvgEllipse(NVGcontext* ctx, float cx, float cy, float rx, float ry);
  // void nvgCircle(NVGcontext* ctx, float cx, float cy, float r);
  // void nvgFill(NVGcontext* ctx);
  // void nvgStroke(NVGcontext* ctx);int nvgCreateFont(NVGcontext* ctx, const char* name, const char* filename);
  // int nvgCreateFontMem(NVGcontext* ctx, const char* name, unsigned char* data, int ndata, int freeData);
  // int nvgFindFont(NVGcontext* ctx, const char* name);
  // int nvgAddFallbackFontId(NVGcontext* ctx, int baseFont, int fallbackFont);
  // int nvgAddFallbackFont(NVGcontext* ctx, const char* baseFont, const char* fallbackFont);
  // void nvgFontSize(NVGcontext* ctx, float size);
  // void nvgFontBlur(NVGcontext* ctx, float blur);
  // void nvgTextLetterSpacing(NVGcontext* ctx, float spacing);
  // void nvgTextLineHeight(NVGcontext* ctx, float lineHeight);
  // void nvgTextAlign(NVGcontext* ctx, int align);
  // void nvgFontFaceId(NVGcontext* ctx, int font);
  // void nvgFontFace(NVGcontext* ctx, const char* font);
  // float nvgText(NVGcontext* ctx, float x, float y, const char* string, const char* end);
  // void nvgTextBox(NVGcontext* ctx, float x, float y, float breakRowWidth, const char* string, const char* end);
  // float nvgTextBounds(NVGcontext* ctx, float x, float y, const char* string, const char* end, float* bounds);
  // void nvgTextBoxBounds(NVGcontext* ctx, float x, float y, float breakRowWidth, const char* string, const char* end, float* bounds);
  // int nvgTextGlyphPositions(NVGcontext* ctx, float x, float y, const char* string, const char* end, NVGglyphPosition* positions, int maxPositions);
  // void nvgTextMetrics(NVGcontext* ctx, float* ascender, float* descender, float* lineh);
  // int nvgTextBreakLines(NVGcontext* ctx, const char* string, const char* end, float breakRowWidth, NVGtextRow* rows, int maxRows);


  napi_set_named_property(env, handle, "gl", gl);

  napi_value nvgSave_;
  napi_create_function(env, "save", NAPI_AUTO_LENGTH, __nvgSave, NULL, &nvgSave_);
  napi_set_named_property(env, handle, "save", nvgSave_);

  napi_value nvgRestore_;
  napi_create_function(env, "restore", NAPI_AUTO_LENGTH, __nvgRestore, NULL, &nvgRestore_);
  napi_set_named_property(env, handle, "restore", nvgRestore_);

  napi_value nvgBeginPath_;
  napi_create_function(env, "beginPath", NAPI_AUTO_LENGTH, __nvgBeginPath, NULL, &nvgBeginPath_);
  napi_set_named_property(env, handle, "beginPath", nvgBeginPath_);

  napi_value nvgMoveTo_;
  napi_create_function(env, "moveTo", NAPI_AUTO_LENGTH, __nvgMoveTo, NULL, &nvgMoveTo_);
  napi_set_named_property(env, handle, "moveTo", nvgMoveTo_);

  napi_value nvgLineTo_;
  napi_create_function(env, "lineTo", NAPI_AUTO_LENGTH, __nvgLineTo, NULL, &nvgLineTo_);
  napi_set_named_property(env, handle, "lineTo", nvgLineTo_);

  napi_value nvgClosePath_;
  napi_create_function(env, "closePath", NAPI_AUTO_LENGTH, __nvgClosePath, NULL, &nvgClosePath_);
  napi_set_named_property(env, handle, "closePath", nvgClosePath_);

  napi_value nvgFill_;
  napi_create_function(env, "fill", NAPI_AUTO_LENGTH, __nvgFill, NULL, &nvgFill_);
  napi_set_named_property(env, handle, "fill", nvgFill_);

  napi_value nvgStroke_;
  napi_create_function(env, "stroke", NAPI_AUTO_LENGTH, __nvgStroke, NULL, &nvgStroke_);
  napi_set_named_property(env, handle, "stroke", nvgStroke_);

  napi_value nvgFillColor_;
  napi_create_function(env, "fillColor", NAPI_AUTO_LENGTH, __nvgFillColor, NULL, &nvgFillColor_);
  napi_set_named_property(env, handle, "fillColor", nvgFillColor_);

  DefineAPI(fillPaint);

  napi_value nvgStrokeColor_;
  napi_create_function(env, "strokeColor", NAPI_AUTO_LENGTH, __nvgStrokeColor, NULL, &nvgStrokeColor_);
  napi_set_named_property(env, handle, "strokeColor", nvgStrokeColor_);

  napi_value nvgStrokeWidth_;
  napi_create_function(env, "strokeWidth", NAPI_AUTO_LENGTH, __nvgStrokeWidth, NULL, &nvgStrokeWidth_);
  napi_set_named_property(env, handle, "strokeWidth", nvgStrokeWidth_);

  napi_value nvgEndFrame_;
  napi_create_function(env, "endFrame", NAPI_AUTO_LENGTH, __nvgEndFrame, NULL, &nvgEndFrame_);
  napi_set_named_property(env, handle, "endFrame", nvgEndFrame_);

  DefineAPI(createImageRGBA);
  DefineAPI(deleteImage);
  DefineAPI(imagePattern);
  DefineAPI(freePaint);

  frame.data = new uint8_t[200 * 200 * 4];
  frame.width = 200;
  frame.height = 200;
  for (int i = 0; i < 200 * 200 * 4; i ++) {
    frame.data[i] = random(0, 255);
  }
  uint64_t uaddr = reinterpret_cast<uint64_t>(&frame);
  napi_set_named_property(env, handle, "data", napi_encoder<uint64_t>::encode(env, uaddr));

  return handle;
}

napi_value Init(napi_env env, napi_value exports) {

  InitializePaints();

  napi_value init_nanovg;
  napi_create_function(env, "initNanoVG", NAPI_AUTO_LENGTH, __nanovg_webgl2_init, NULL, &init_nanovg);

  napi_set_named_property(env, exports, "initNanoVG", init_nanovg);

  return exports;
}

NAPI_MODULE(NANOVG_NODE_WEBGL, Init);