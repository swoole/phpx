#ifdef PPROF_ON
#include <gperftools/profiler.h>
#endif

#include <typephp_runtime.h>

#ifndef TYPEPHP_PROJECT_NAME
#error "TYPEPHP_PROJECT_NAME must be defined for the embedded runtime"
#endif

TYPEPHP_EMBED_GET_MODULE_FUNCTION(TYPEPHP_PROJECT_NAME);

TYPEPHP_RUNTIME_INIT_FUNCTION(TYPEPHP_PROJECT_NAME) {
    return typephp_runtime_start(TYPEPHP_EMBED_GET_MODULE(TYPEPHP_PROJECT_NAME), argc, argv);
}

TYPEPHP_RUNTIME_SHUTDOWN_FUNCTION(TYPEPHP_PROJECT_NAME) {
    typephp_runtime_stop();
}

#ifndef TYPEPHP_NO_MAIN
int main(int cpp_argc, char **cpp_argv) {
    int rc = 0;
#ifdef PPROF_ON
    ProfilerStart(PROF_OUTPUT_FILE);
#endif
    rc = TYPEPHP_RUNTIME_INIT(TYPEPHP_PROJECT_NAME)(cpp_argc, cpp_argv);
#ifdef PPROF_ON
    ProfilerStop();
#endif
    TYPEPHP_RUNTIME_SHUTDOWN(TYPEPHP_PROJECT_NAME)();
    return rc;
}
#endif
