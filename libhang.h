#ifdef LIBHANG_STATIC
#  define LIBHANG_API
#else
#  ifdef libhang_EXPORTS
#    define LIBHANG_API __declspec(dllexport)
#  else
#    define LIBHANG_API __declspec(dllimport)
#  endif
#endif

#ifdef __cplusplus
extern "C" {
#endif

void LIBHANG_API dohang();

#ifdef __cplusplus
}
#endif
