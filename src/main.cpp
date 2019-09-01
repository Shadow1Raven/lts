
#include <lts/main.hpp>

using namespace std;

namespace core = irr::core;
namespace scene = irr::scene;
namespace video = irr::video;

lts::map::Lot * loadTestLot();
void loadModels(irr::IrrlichtDevice &device);

int main(void)
{
	lts::map::Lot *testLot = loadTestLot();

	irr::SIrrlichtCreationParameters irrlichtCreationParameters;

	irr::IrrlichtDevice *device = irr::createDeviceEx(irrlichtCreationParameters);
	device->setWindowCaption(L"LTS");
	scene::ISceneManager *sceneManager = device->getSceneManager();
	video::IVideoDriver *videoDriver = device->getVideoDriver();

	loadModels(*device);

	lts::scene::LotSceneNode lotSceneNode(*testLot, nullptr, sceneManager);
	sceneManager->getRootSceneNode()->addChild(&lotSceneNode);
	sceneManager->setAmbientLight(irr::video::SColorf(1.0, 1.0, 1.0, 1.0));

	scene::ICameraSceneNode *camera = sceneManager->addCameraSceneNodeFPS(nullptr, 40.0f, 0.01);
	camera->setPosition({0, 3, -2});
	camera->setTarget({0, 1, 1});

	irr::scene::IAnimatedMesh *personMesh = sceneManager->getMeshCache()->getMeshByName(u8"lts::core::person");
	irr::scene::IAnimatedMeshSceneNode *personMeshNode = sceneManager->addAnimatedMeshSceneNode(personMesh);

	while (device->run())
	{
		device->getVideoDriver()->beginScene();
		sceneManager->drawAll();

		device->getVideoDriver()->endScene();
		device->sleep(1000 / 60);
	}

	return 0;
}

lts::map::Lot * loadTestLot()
{
	irr::IrrlichtDevice *device = irr::createDevice(irr::video::EDT_NULL);
	irr::io::IFileSystem *fileSystem = device->getFileSystem();
	irr::io::IArchiveLoader *loader;
	uint32_t i = 0;
	while((loader = fileSystem->getArchiveLoader(i)) && (!loader->isALoadableFileFormat(irr::io::EFAT_ZIP)))
	{
		i++;

		if (i >= fileSystem->getArchiveLoaderCount())
			throw new std::runtime_error("No ZIP archive loader found.");
	}

	irr::io::IFileArchive *archive = loader->createArchive(u8"testlot/testlot.zip", false, false);
	lts::map::Lot *lot = new lts::map::Lot(*archive);

	device->closeDevice();
	return lot;
}

void loadModels(irr::IrrlichtDevice &device)
{
	irr::scene::ISceneManager &sceneManager = *device.getSceneManager();
	irr::scene::IAnimatedMesh *personMesh = sceneManager.getMesh(u8"models/person.3ds");
	irr::scene::IAnimatedMesh *cheapShelfMesh = sceneManager.getMesh(u8"models/shelf_cheap.3ds");

	sceneManager.getMeshCache()->addMesh(u8"lts::core::person", personMesh);
	sceneManager.getMeshCache()->addMesh(u8"lts::core::shelf_cheap", cheapShelfMesh);
}
