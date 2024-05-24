#include "GameObject.h"
#include <algorithm>
#include <vector>


static GameObject* m_root;

// to be implemented when collider struct is made > Collider* m_collider;

GameObject::GameObject()
{
	Parent = nullptr;

	//set localposition.z to 1 to ensure all children will inherit translations
	LocalPosition = MathClasses::Vector3(0, 0, 1);
	LocalRotation = 0;
	LocalScale = MathClasses::Vector3(1, 1, 1);
}

GameObject* GameObject::getRoot()
{
	return m_root;
}

void GameObject::setRoot(GameObject* go)
{
	m_root = go;
}

void GameObject::OnUpdate(float deltaTime)
{
	//left blank
	//OnUpdate->this;
	
}

void GameObject::OnDraw()
{
	//left blank
}

void GameObject::Update(float deltaTime)
{
	OnUpdate(deltaTime);
	
	for (int i = 0; i < Children.size(); i++)
	{
		GetChild(i)->Update(deltaTime);
	}
}

void GameObject::Draw()
{
	OnDraw();
	
	for (int i = 0; i < Children.size(); i++)
	{
		GetChild(i)->Draw();
	}
}

void GameObject::SetParent(GameObject* newParent)
{
	//remove existing if needed
	if (Parent != nullptr)
	{
		//return an iterator to this child in its parents vector of children
		auto findIt = std::find(Parent->Children.begin(), Parent->Children.end(), this);

		//if found, iterator will be something besides the end of the vector
		if (findIt != Parent->Children.end())
		{
			Parent->Children.erase(findIt);
			Parent = nullptr;
		}
	}

	//add to new parent if any
	if (newParent != nullptr)
	{
		Parent = newParent;
		Parent->Children.push_back(this);
	}
}

GameObject* GameObject::GetParent()
{
	return Parent;
}

const GameObject* GameObject::GetParent() const
{
	return Parent;
}

GameObject* GameObject::GetChild(size_t childIndex)
{
	return Children[childIndex];
}

const GameObject* GameObject::GetChild(size_t childIndex) const
{
	return Children[childIndex];
}

MathClasses::Vector3 GameObject::GetLocalPosition() const
{
	return LocalPosition;
}

void GameObject::SetLocalPosition(MathClasses::Vector3 newPosition)
{
	LocalPosition = newPosition;
}

void GameObject::SetLocalPosition(float newX, float newY)
{
	LocalPosition = MathClasses::Vector3(newX, newY, LocalPosition.z);
}

float GameObject::GetLocalRotation() const
{
	return LocalRotation;
}

void GameObject::SetLocalRotation(float newRotation)
{
	LocalRotation = newRotation;
}

MathClasses::Vector3 GameObject::GetLocalScale() const
{
	return LocalScale;
}

void GameObject::SetLocalScale(MathClasses::Vector3 newScale)
{
	LocalScale = newScale;
}

void GameObject::SetLocalScale(float newX, float newY)
{
	LocalScale = MathClasses::Vector3(newX, newY, LocalScale.z);
}

MathClasses::Matrix3 GameObject::GetLocalMatrix() const
{
	return
		MathClasses::Matrix3::MakeTranslation(LocalPosition) * MathClasses::Matrix3::MakeRotateZ(LocalRotation) * MathClasses::Matrix3::MakeScale(LocalScale.x, LocalScale.y);
}

MathClasses::Matrix3 GameObject::GetWorldMatrix() const
{
	//if no parent use as is
	if (Parent == nullptr)
	{
		return GetLocalMatrix();
	}
	//combine w/ parents world
	else
	{
		return Parent->GetWorldMatrix() * GetLocalMatrix();
	}
}

MathClasses::Vector3 GameObject::GetWorldPosition() const
{
	MathClasses::Matrix3 worldMat = GetWorldMatrix();
	return MathClasses::Vector3(worldMat.m7, worldMat.m8, worldMat.m9);
}

float GameObject::GetWorldRotation() const
{
	MathClasses::Vector3 fwd = GetForward();
	return atan2(fwd.y, fwd.x);
}

MathClasses::Vector3 GameObject::GetWorldScale() const
{
	//calculate the local transform matrix
	MathClasses::Matrix3 myTransform = GetWorldMatrix();
	return MathClasses::Vector3(MathClasses::Vector3(myTransform.m1, myTransform.m2, 0).Magnitude(), MathClasses::Vector3(myTransform.m4, myTransform.m5, 0).Magnitude(), 1.0f);
}

MathClasses::Vector3 GameObject::GetForward() const
{
	auto mat = GetWorldMatrix();
	return MathClasses::Vector3(mat[0], mat[1], mat[2]);
}

void GameObject::Translate(float x, float y)
{
	LocalPosition += MathClasses::Vector3(x, y, 0);
}

void GameObject::Translate(MathClasses::Vector3 translation)
{
	LocalPosition += translation;
}

void GameObject::Rotate(float radians)
{
	LocalRotation += radians;
}

void GameObject::Scale(float x, float y)
{
	LocalScale *= MathClasses::Vector3(x, y, 1);
}

void GameObject::Scale(MathClasses::Vector3 scaling)
{
	LocalScale *= scaling;
}

void GameObject::GetColliders(std::vector<Collider*>& GC)
{
	//does THIS gameobject have a collider?
	//if so, add to the vector (push_back collider to the vector)

	if (m_collider != nullptr)
	{
		GC.push_back(m_collider);
	}

	for (int i = 0; i < Children.size(); i++)
	{
		//call getcolliders for each child
		GetChild(i)->GetColliders(GC);
	}
}
