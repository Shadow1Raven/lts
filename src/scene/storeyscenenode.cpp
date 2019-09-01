
#include <lts/scene/storeyscenenode.hpp>

namespace lts
{
	namespace scene
	{
		StoreySceneNode::StoreySceneNode(lts::map::Storey &storey, irr::scene::ISceneNode *parent, irr::scene::ISceneManager *mgr, int32_t id) : irr::scene::ISceneNode(parent, mgr, id)
		{
			this->storey = &storey;
		}

		const irr::core::aabbox3df & StoreySceneNode::getBoundingBox() const
		{

		}

		void StoreySceneNode::OnRegisterSceneNode()
		{
			if (this->IsVisible)
				this->SceneManager->registerNodeForRendering(this);

			this->ISceneNode::OnRegisterSceneNode();
		}

		void StoreySceneNode::render()
		{
			if (this->reattachNodes)
			{
				for (auto child : this->getChildren())
					this->removeChild(child);

				irr::scene::IMeshCache *meshCache = this->SceneManager->getMeshCache();
				for (auto x = this->storey->objectIterator(); x != this->storey->constEnd(); x++)
				{
					const lts::map::ObjectLocation &object = *x;
					const ObjectIdentifier &objectIdentifier = object.getObjectIdentifier();

					lts::map::TileAlignedBoundingBox boundingBox = object.getTileAlignedBoundingBox();
					TileAlignedBox box = boundingBox.getTileAlignedBox();

					irr::scene::IAnimatedMesh *mesh = meshCache->getMeshByName(objectIdentifier.c_str());

					const irr::core::aabbox3df &widthsAndHeights = mesh->getBoundingBox();
					irr::core::vector3df meshNodeLocation = irr::core::vector3df(box.UpperLeftCorner.X, boundingBox.getLowY(), box.UpperLeftCorner.Y);
					irr::scene::IAnimatedMeshSceneNode *meshNode = this->SceneManager->addAnimatedMeshSceneNode(mesh, this, -1, meshNodeLocation);

					meshNode->render();
				}

				this->reattachNodes = false;
			}
		}
	}
}
