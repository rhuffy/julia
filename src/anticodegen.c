// This file is a part of Julia. License is MIT: https://julialang.org/license

#include "julia.h"
#include "julia_internal.h"

#include "intrinsics.h"

int globalUnique = 0;
jl_cgparams_t jl_default_cgparams = {1, 1, 1, 1, 0, NULL, NULL, NULL, NULL, NULL};

#define UNAVAILABLE { jl_errorf("%s: not available in this build of Julia", __func__); }

JL_DLLEXPORT void *jl_create_native(jl_array_t *methods, LLVMContextRef llvmctxt, const jl_cgparams_t *cgparams, int _policy) UNAVAILABLE
JL_DLLEXPORT void jl_dump_native(void *native_code,
        const char *bc_fname, const char *unopt_bc_fname, const char *obj_fname, const char *asm_fname,
        const char *sysimg_data, size_t sysimg_len) UNAVAILABLE
JL_DLLEXPORT int32_t jl_get_llvm_gv(void *native_code, jl_value_t *p) UNAVAILABLE

JL_DLLEXPORT void jl_extern_c(jl_function_t *f, jl_value_t *rt, jl_value_t *argt, char *name) UNAVAILABLE
JL_DLLEXPORT jl_value_t *jl_dump_method_asm(jl_method_instance_t *linfo, size_t world,
        char raw_mc, char getwrapper, const char* asm_variant, const char *debuginfo, char binary) UNAVAILABLE
JL_DLLEXPORT jl_value_t *jl_dump_function_ir(void *f, char strip_ir_metadata, char dump_module, const char *debuginfo) UNAVAILABLE
JL_DLLEXPORT void *jl_get_llvmf_defn(jl_method_instance_t *linfo, LLVMContextRef ctxt, size_t world, char getwrapper, char optimize, const jl_cgparams_t params) UNAVAILABLE

JL_DLLEXPORT void *jl_LLVMCreateDisasm(const char *TripleName, void *DisInfo, int TagType, void *GetOpInfo, void *SymbolLookUp) UNAVAILABLE
JL_DLLEXPORT size_t jl_LLVMDisasmInstruction(void *DC, uint8_t *Bytes, uint64_t BytesSize, uint64_t PC, char *OutString, size_t OutStringSize) UNAVAILABLE

JL_DLLEXPORT void jl_init_codegen(void) { }

JL_DLLEXPORT int jl_getFunctionInfo(jl_frame_t **frames, uintptr_t pointer, int skipC, int noInline)
{
    return 0;
}

JL_DLLEXPORT void jl_register_fptrs(uint64_t sysimage_base, const struct _jl_sysimg_fptrs_t *fptrs,
                       jl_method_instance_t **linfos, size_t n)
{
    (void)sysimage_base; (void)fptrs; (void)linfos; (void)n;
}

JL_DLLEXPORT jl_code_instance_t *jl_generate_fptr(jl_method_instance_t *mi JL_PROPAGATES_ROOT, size_t world)
{
    return NULL;
}

JL_DLLEXPORT void jl_generate_fptr_for_unspecialized(jl_code_instance_t *unspec)
{
    jl_atomic_store_release(&unspec->invoke, &jl_fptr_interpret_call);
}

JL_DLLEXPORT uint32_t jl_get_LLVM_VERSION(void)
{
    return 0;
}

JL_DLLEXPORT int jl_compile_extern_c(LLVMModuleRef llvmmod, void *params, void *sysimg, jl_value_t *declrt, jl_value_t *sigt)
{
    return 0;
}

JL_DLLEXPORT void jl_teardown_codegen(void)
{
}

JL_DLLEXPORT size_t jl_jit_total_bytes(void)
{
    return 0;
}

JL_DLLEXPORT void jl_lock_profile(void)
{
}

JL_DLLEXPORT void jl_unlock_profile(void)
{
}

JL_DLLEXPORT void jl_dump_compiles(void *s)
{
}

JL_DLLEXPORT void jl_dump_emitted_mi_name(void *s)
{
}

JL_DLLEXPORT void jl_dump_llvm_opt(void *s)
{
}

JL_DLLEXPORT jl_value_t *jl_dump_fptr_asm(uint64_t fptr, char raw_mc, const char* asm_variant, const char *debuginfo, char binary) UNAVAILABLE

JL_DLLEXPORT jl_value_t *jl_dump_function_asm(void *F, char raw_mc, const char* asm_variant, const char *debuginfo, char binary) UNAVAILABLE

JL_DLLEXPORT LLVMContextRef jl_get_ee_context(void) UNAVAILABLE

JL_DLLEXPORT void jl_get_function_id(void *native_code, jl_code_instance_t *ncode,
        int32_t *func_idx, int32_t *specfunc_idx) UNAVAILABLE

JL_DLLEXPORT void *jl_get_llvm_context(void *native_code) UNAVAILABLE

JL_DLLEXPORT void *jl_get_llvm_function(void *native_code, uint32_t idx) UNAVAILABLE

JL_DLLEXPORT void *jl_get_llvm_module(void *native_code) UNAVAILABLE

JL_DLLEXPORT void *jl_type_to_llvm(jl_value_t *jt, LLVMContextRef llvmctxt, bool_t *isboxed) UNAVAILABLE

JL_DLLEXPORT jl_value_t *jl_get_libllvm(void) JL_NOTSAFEPOINT
{
    return jl_nothing;
}

JL_DLLEXPORT uint64_t jl_getUnwindInfo(uint64_t dwAddr)
{
    return 0;
}

JL_DLLEXPORT void jl_add_optimization_passes(void *PM, int opt_level, int lower_intrinsics) UNAVAILABLE

JL_DLLEXPORT void LLVMExtraAddLowerSimdLoopPass(void *PM) UNAVAILABLE

JL_DLLEXPORT void LLVMExtraAddFinalLowerGCPass(void *PM) UNAVAILABLE

JL_DLLEXPORT void LLVMExtraAddPropagateJuliaAddrspaces(void *PM) UNAVAILABLE

JL_DLLEXPORT void LLVMExtraAddRemoveJuliaAddrspacesPass(void *PM) UNAVAILABLE

JL_DLLEXPORT void LLVMExtraAddCombineMulAddPass(void *PM) UNAVAILABLE

JL_DLLEXPORT void LLVMExtraAddMultiVersioningPass(void *PM) UNAVAILABLE

JL_DLLEXPORT void LLVMExtraAddLowerExcHandlersPass(void *PM) UNAVAILABLE

JL_DLLEXPORT void LLVMExtraAddLateLowerGCFramePass(void *PM) UNAVAILABLE

JL_DLLEXPORT void LLVMExtraJuliaLICMPass(void *PM) UNAVAILABLE

JL_DLLEXPORT void LLVMExtraAddAllocOptPass(void *PM) UNAVAILABLE

JL_DLLEXPORT void LLVMExtraAddLowerPTLSPass(void *PM, bool_t imaging_mode) UNAVAILABLE

JL_DLLEXPORT void LLVMExtraAddRemoveNIPass(void *PM) UNAVAILABLE

JL_DLLEXPORT void LLVMExtraAddGCInvariantVerifierPass(void *PM, bool_t Strong) UNAVAILABLE

JL_DLLEXPORT void LLVMExtraAddDemoteFloat16Pass(void *PM) UNAVAILABLE

JL_DLLEXPORT void LLVMExtraAddCPUFeaturesPass(void *PM) UNAVAILABLE

JL_DLLEXPORT int _ZN4llvm16itanium_demangle19parse_discriminatorEPKcS2_(void *A, void*B) {
    return 0;
}
JL_DLLEXPORT int _ZN4llvm18raw_string_ostreamD1Ev(void *A) {
    return 0;
}
JL_DLLEXPORT void _ZN4llvm5APInt16OrAssignSlowCaseERKS0_(void *A, void*B) UNAVAILABLE
JL_DLLEXPORT void _ZN4llvm5APInt17AndAssignSlowCaseERKS0_(void *A, void*B) UNAVAILABLE
JL_DLLEXPORT void _ZN4llvm5APInt17XorAssignSlowCaseERKS0_(void *A, void*B) UNAVAILABLE
JL_DLLEXPORT int _ZNK4llvm5APInt13EqualSlowCaseERKS0_(void *A, void*B) {
    return 0;
}
JL_DLLEXPORT int dlinfo(void *A, void*B, void*C) {
    return 0;
}
JL_DLLEXPORT void jl_set_fiber(void *PM) UNAVAILABLE
JL_DLLEXPORT void jl_start_fiber_set(void *PM) UNAVAILABLE
JL_DLLEXPORT void jl_start_fiber_swap(void *PM) UNAVAILABLE
JL_DLLEXPORT void jl_swap_fiber(void *PM) UNAVAILABLE
JL_DLLEXPORT int pthread_kill(pthread_t, int) {
    return 0;
}
JL_DLLEXPORT int sigaltstack(const stack_t *__restrict, stack_t *__restrict) {
    return 0;
}
JL_DLLEXPORT int sysinfo(void *PM) {
    return 0;
}
JL_DLLEXPORT int timer_create (clockid_t, struct sigevent *__restrict, timer_t *__restrict) {
    return 0;
}
JL_DLLEXPORT int timer_delete (timer_t) {
    return 0;
}
JL_DLLEXPORT int timer_settime (timer_t, int, const struct itimerspec *__restrict, struct itimerspec *__restrict) {
    return 0;
}