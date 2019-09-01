#ifndef LTS_STOREYSCENENODE_HPP
#define LTS_STOREYSCENENODE_HPP

#include <irrlicht/ISceneManager.h>
#include <irrlicht/ISceneNode.h>
#include <irrlicht/IMeshCache.h>
#include <irrlicht/IAnimatedMeshSceneNode.h>

#include <lts/map/storey.hpp>

namespace lts
{
	namespace scene
	{
		class StoreySceneNode : public irr::scene::ISceneNode
		{
			private:
			lts::map::Storey *storey;
			bool reattachNodes = true;

			public:
			StoreySceneNode(lts::map::Storey &storey, irr::scene::ISceneNode *parent, irr::scene::ISceneManager *mgr, int32_t id = -1);

			const irr::core::aabbox3df & getBoundingBox() const;
			void OnRegisterSceneNode();
			void render();
		};
	}
}

#endif
