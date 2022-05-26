#include <xmmintrin.h>

namespace SIMD
{
    struct alignas(16) sse_mat4
    {
        float data[16];
    };

    struct vec4
    {
        __m128 xmm;

        vec4 (__m128 v) : xmm (v) {}

        vec4 (float v) { xmm = _mm_set1_ps(v); }

        vec4 (float x, float y, float z, float w)
        { xmm = _mm_set_ps(w,z,y,x); }

        vec4 (const float *v) { xmm = _mm_load_ps(v); }

        vec4 operator* (const vec4 &v) const
        { return vec4(_mm_mul_ps(xmm, v.xmm)); }

        vec4 operator+ (const vec4 &v) const
        { return vec4(_mm_add_ps(xmm, v.xmm)); }

        vec4 operator- (const vec4 &v) const
        { return vec4(_mm_sub_ps(xmm, v.xmm)); }

        vec4 operator/ (const vec4 &v) const
        { return vec4(_mm_div_ps(xmm, v.xmm)); }

        void operator*= (const vec4 &v)
        { xmm = _mm_mul_ps(xmm, v.xmm); }

        void operator+= (const vec4 &v)
        { xmm = _mm_add_ps(xmm, v.xmm); }

        void operator-= (const vec4 &v)
        { xmm = _mm_sub_ps(xmm, v.xmm); }

        void operator/= (const vec4 &v)
        { xmm = _mm_div_ps(xmm, v.xmm); }

        void operator>> (float *v)
        { _mm_store_ps(v, xmm); }

    };

    inline void mmul_vec4(const float* a, const float* b, float* r)
    {
        for (int i = 0; i < 16; i += 4)
        {
            vec4 rl = vec4(a) * vec4(b[i]);

            rl += vec4(&a[4]) * vec4(b[i + 1]);
            rl += vec4(&a[8]) * vec4(b[i + 2]);
            rl += vec4(&a[12]) * vec4(b[i + 3]);

            rl >> &r[i];
        }
    }
}