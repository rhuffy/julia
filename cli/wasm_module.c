// This file is a part of Julia. License is MIT: https://julialang.org/license
#include <emscripten/emscripten.h>
#include <dlfcn.h>

// #include "jl_wasm_exports.h"
// #include "platform.h"
// #include "julia.h"
// #include "julia_assert.h"

#include "loader.h"

// void EMSCRIPTEN_KEEPALIVE jl_eval_and_print(const char *line)
// {
//     JL_TRY {
//         jl_value_t *val = (jl_value_t*)jl_eval_string(line);
//         if (jl_exception_occurred()) {
//             // jl_printf(JL_STDERR, "error during run:\n");
//             // jl_static_show(JL_STDERR, jl_current_exception());
//             jl_exception_clear();
//         }
//         else if (val) {
//             // jl_static_show(JL_STDOUT, val);
//         }
//         // jl_printf(JL_STDOUT, "\n");
//     }
//     JL_CATCH {
//         // jl_printf(JL_STDERR, "\nparser error:\n");
//         // jl_static_show(JL_STDERR, jl_current_exception());
//         // jl_printf(JL_STDERR, "\n");
//         jlbacktrace();
//     }
// }

int EMSCRIPTEN_KEEPALIVE jl_initialize() {

    // void* libjulia_handle = dlopen("libjulia.so", RTLD_NOW);
    // if (!libjulia_handle) {
    //     printf("%s \n", dlerror());
    //     return 1;
    // }
    // int (*jl_load_repl)() = dlsym(libjulia_handle, "jl_load_repl");
    // if (!jl_load_repl) {
    //     printf("Symbol not found\n");
    //     return 2;
    // }

    
    // exit(69);
    char* argv[]={"./julia", "-C", "\"native\"", "--compile=no", "--startup-file=no", "-J", "sys.ji", 0};
    int argc = 5;
    int ret = jl_load_repl(argc, argv);
    return ret;
    // char *argv = argv2;
    // libsupport_init();
    // jl_parse_opts(&argc, (char***)&argv);
    // julia_init(jl_options.image_file_specified ? JL_IMAGE_CWD : JL_IMAGE_JULIA_HOME);
}
