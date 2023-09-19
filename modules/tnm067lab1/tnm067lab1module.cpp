#include <modules/tnm067lab1/tnm067lab1module.h>
#include <modules/tnm067lab1/processors/imagetoheightfield.h>
#include <modules/tnm067lab1/processors/imageupsampler.h>
#include <modules/tnm067lab1/processors/imagemappingcpu.h>

namespace inviwo {

TNM067Lab1Module::TNM067Lab1Module(InviwoApplication* app) : InviwoModule(app, "TNM067Lab1") {
    // Add a directory to the search path of the Shadermanager
    // ShaderManager::getPtr()->addShaderSearchPath(getPath(ModulePath::GLSL));

    // Register objects that can be shared with the rest of inviwo here:
    // Processors
    registerProcessor<ImageToHeightfield>();
    registerProcessor<ImageUpsampler>();
    registerProcessor<ImageMappingCPU>();
}

}  // namespace inviwo
