cmake_minimum_required(VERSION 3.5)
set(SOURCES common.h
            fvad.c
            signal_processing/division_operations.c
            signal_processing/energy.c
            signal_processing/get_scaling_square.c
            signal_processing/resample_48khz.c
            signal_processing/resample_by_2_internal.h
            signal_processing/resample_by_2_internal.c
            signal_processing/resample_fractional.c
            signal_processing/signal_processing_library.h
            signal_processing/spl_inl.h
            signal_processing/spl_inl.c
            vad/vad_core.h
            vad/vad_core.c
            vad/vad_filterbank.h
            vad/vad_filterbank.c
            vad/vad_gmm.h
            vad/vad_gmm.c
            vad/vad_sp.h
            vad/vad_sp.c)

add_library(fvad STATIC ${SOURCES})

target_include_directories(fvad
    PUBLIC
        ../include
)

set_property(TARGET fvad PROPERTY POSITION_INDEPENDENT_CODE 1)
install(TARGETS fvad DESTINATION lib)
