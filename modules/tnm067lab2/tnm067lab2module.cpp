#include <modules/tnm067lab2/tnm067lab2module.h>
#include <modules/tnm067lab2/processors/hydrogengenerator.h>


namespace inviwo {

TNM067Lab2Module::TNM067Lab2Module(InviwoApplication* app) : InviwoModule(app, "TNM067Lab2") {
    // Add a directory to the search path of the Shadermanager
    // ShaderManager::getPtr()->addShaderSearchPath(getPath(ModulePath::GLSL));

    // Register objects that can be shared with the rest of inviwo here:
    // Processors
    registerProcessor<HydrogenGenerator>();
}

}  // namespace inviwo
