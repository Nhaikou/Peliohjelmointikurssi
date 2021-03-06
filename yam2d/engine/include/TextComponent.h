// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// http://code.google.com/p/yam2d/
//
// Copyright (c) 2013 Mikko Romppainen
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of
// this software and associated documentation files (the "Software"), to deal in the
// Software without restriction, including without limitation the rights to use, copy,
// modify, merge, publish, distribute, sublicense, and/or sell copies of the Software,
// and to permit persons to whom the Software is furnished to do so, subject to the
// following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies
// or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
// INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
// PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE
// FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
// OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
#ifndef TEXTGAMEOBJECT_H_
#define TEXTGAMEOBJECT_H_

#include <vector>
#include <string>
#include <map>
#include "SpriteBatch.h"

#include "GameObject.h"
#include "PropertySet.h"
#include "SpriteSheet.h"
#include "SpriteAnimation.h"
#include "Map.h"
#include "Tileset.h"
#include "Text.h"
#include "Texture.h"

namespace yam2d
{
	

class Tileset;
class Map;
class SpriteSheet;


/**
 * Class for TextGameObject.
 *
 * @ingroup yam2d
 * @author Mikko Romppainen (mikko@kajakbros.com) 
 */

class TextComponent : public Component
{
public:
	TextComponent(GameObject* owner, SpriteSheet* font)
		: Component(owner,Component::getDefaultProperties())
		, m_text(new Text(owner, font))
	{
		assert(owner != 0); // Must have owner game object
	}

	virtual ~TextComponent() {}
	
	Text* getText() const { return m_text.ptr(); }

	GameObject* getGameObject() { return (GameObject*)getOwner(); }
	const GameObject* getGameObject() const { return (const GameObject*)getOwner(); }

private:
	Ref<Text>		m_text;

	TextComponent();
	TextComponent(const TextComponent& o);
	TextComponent& operator=(const TextComponent& o);
};


}

#endif




