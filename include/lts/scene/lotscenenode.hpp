#ifndef LTS_LOTSCENENODE_HPP
#define LTS_LOTSCENENODE_HPP

#include <irrlicht/IVideoDriver.h>
#include <irrlicht/ISceneManager.h>
#include <irrlicht/ISceneNode.h>

#include <lts/map/lot.hpp>
#include <lts/scene/storeyscenenode.hpp>

namespace lts
{
	namespace scene
	{
		class LotSceneNode : public irr::scene::ISceneNode
		{
			private:
			const irr::core::aabbox3df boundingBox = irr::core::aabbox3df(-128, -128 * 3, -128, 128, 128 * 3, 128);
			lts::map::Lot *lot;
			StoreySceneNode *storeySceneNodes[256] { nullptr };

			public:
			LotSceneNode(lts::map::Lot &lot, irr::scene::ISceneNode *parent, irr::scene::ISceneManager *sceneManager, int32_t id = -1);

			const irr::core::aabbox3df & getBoundingBox() const;
			void OnRegisterSceneNode();
			void render();
		};
	}
}

#endif
