ivw_module(TNM067lab4)

set(HEADER_FILES
    include/inviwo/tnm067lab4/tnm067lab4module.h
    include/inviwo/tnm067lab4/tnm067lab4moduledefine.h
    include/inviwo/tnm067lab4/processors/lineintegralconvolution.h
    include/inviwo/tnm067lab4/processors/vectorfieldinformation.h
)
ivw_group("Header Files" ${HEADER_FILES})

set(SOURCE_FILES
    src/tnm067lab4module.cpp
    src/processors/lineintegralconvolution.cpp
    src/processors/vectorfieldinformation.cpp
)
ivw_group("Source Files" ${SOURCE_FILES})

set(SHADER_FILES
	glsl/lineintegralconvolution.frag
    glsl/lineintegralconvolution.vert
    glsl/vectorfieldinformation.frag
    glsl/vectorfieldinformation.vert
)
ivw_group("Shader Files" ${SHADER_FILES})

set(TEST_FILES
    tests/unittests/tnm067lab4-unittest-main.cpp
)
ivw_add_unittest(${TEST_FILES})

ivw_create_module(${SOURCE_FILES} ${HEADER_FILES} ${SHADER_FILES})

# Add shader directory to install package
#ivw_add_to_module_pack(${CMAKE_CURRENT_SOURCE_DIR}/glsl)
ivw_folder(inviwo-module-tnm067lab4 TNM067)