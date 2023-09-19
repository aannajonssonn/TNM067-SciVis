ivw_module(TNM067lab3)

set(HEADER_FILES
    include/inviwo/tnm067lab3/tnm067lab3module.h
    include/inviwo/tnm067lab3/tnm067lab3moduledefine.h
    include/inviwo/tnm067lab3/processors/marchingtetrahedra.h
)
ivw_group("Header Files" ${HEADER_FILES})

set(SOURCE_FILES
    src/tnm067lab3module.cpp
    src/processors/marchingtetrahedra.cpp
)
ivw_group("Source Files" ${SOURCE_FILES})

set(SHADER_FILES
	# Add shaders
)
ivw_group("Shader Files" ${SHADER_FILES})

set(TEST_FILES
    tests/unittests/tnm067lab3-unittest-main.cpp
    tests/unittests/marching-tetrahedra-test.cpp
)
ivw_add_unittest(${TEST_FILES})

ivw_create_module(${SOURCE_FILES} ${HEADER_FILES} ${SHADER_FILES})

# Add shader directory to install package
#ivw_add_to_module_pack(${CMAKE_CURRENT_SOURCE_DIR}/glsl)
ivw_folder(inviwo-module-tnm067lab3 TNM067)