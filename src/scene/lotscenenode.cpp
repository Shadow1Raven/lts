
#include <lts/scene/lotscenenode.hpp>

#include <iostream>

namespace lts
{
	namespace scene
	{
		LotSceneNode::LotSceneNode(lts::map::Lot &lot, irr::scene::ISceneNode *parent, irr::scene::ISceneManager *sceneManager, int32_t id) : irr::scene::ISceneNode(parent, sceneManager, id)
		{
			this->lot = &lot;

			for (int8_t i = -128; i < 127; i++)
			{
				lts::map::Storey *storey = this->lot->getStorey(i);
				if (storey != nullptr)
				{
					this->storeySceneNodes[i + 128] = new StoreySceneNode(*storey, this, this->SceneManager);
				}
			}
		}

		const irr::core::aabbox3df &LotSceneNode::getBoundingBox() const
		{
			return this->boundingBox;
		}

		void LotSceneNode::OnRegisterSceneNode()
		{
			if (this->IsVisible)
				this->SceneManager->registerNodeForRendering(this);

			this->ISceneNode::OnRegisterSceneNode();
		}

		void LotSceneNode::render()
		{
			irr::video::IVideoDriver *driver = this->getSceneManager()->getVideoDriver();
			lts::map::TerrainMap *terrainMap = this->lot->getTerrainMap();
			for (irr::u32 x = 0; x < lot->getExtent().getWidth(); x++)
			{
				irr::video::SColor currentColor(255, (x % 2) * 255, (1 - (x % 2)) * 255, 255);
				for (irr::u32 z = 0; z < lot->getExtent().getHeight(); z++)
				{
					float heightNearLeft = terrainMap->getTerrainHeight(x, z) * 0.1f;
					float heightFarLeft = terrainMap->getTerrainHeight(x, z + 1) * 0.1f;
					float heightNearRight = terrainMap->getTerrainHeight(x + 1, z) * 0.1f;
					float heightFarRight = terrainMap->getTerrainHeight(x + 1, z + 1) * 0.1f;
					float heightAverage = (heightNearLeft + heightNearRight + heightFarLeft + heightFarRight) / 4.0f;

					float x1 = x * 1.0f;
					float x2 = (x + 1) * 1.0f;
					float xCentre = (x1 + x2) * 0.5f;
					float z1 = z * 1.0f;
					float z2 = (z + 1) * 1.0f;
					float zCentre = (z1 + z2) * 0.5f;

					irr::core::aabbox3df box(x1, heightAverage, z1, x2, heightAverage, z2);
					driver->draw3DBox(box, currentColor);

					const float halfBorder = 0.005;
					irr::core::vector3df centre(xCentre, heightAverage, zCentre);
					irr::core::vector3df nearLeft(x1 + halfBorder, heightNearLeft, z1 + halfBorder);
					irr::core::vector3df nearRight(x2 - halfBorder, heightNearRight, z1 + halfBorder);
					irr::core::vector3df farLeft(x1 + halfBorder, heightFarLeft, z2 - halfBorder);
					irr::core::vector3df farRight(x2 - halfBorder, heightFarRight, z2 - halfBorder);

					irr::core::triangle3df bottom(nearLeft, centre, nearRight);
					irr::core::triangle3df left(nearLeft, farLeft, centre);
					irr::core::triangle3df top(farLeft, farRight, centre);
					irr::core::triangle3df right(farRight, nearRight, centre);

					driver->draw3DTriangle(left, currentColor);
					driver->draw3DTriangle(right, currentColor);
					driver->draw3DTriangle(top, currentColor);
					driver->draw3DTriangle(bottom, currentColor);
				}
			}

			for (auto child : this->getChildren())
				child->render();
		}
	}
}
