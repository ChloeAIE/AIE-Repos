#pragma once
#include <vector>
#include "Matrix3.h"
//#include "Collider.h"

struct Collider; //forward declare

class GameObject
{
protected:
	//position of this object relative to its parent
	MathClasses::Vector3 LocalPosition;

	//the rotation relative to parent in radians??????????????
	float LocalRotation;

	//Scale relative
	MathClasses::Vector3 LocalScale;

	//pointer to the parent
	GameObject* Parent;

	//Vector of children
	std::vector<GameObject*> Children;

	//called when this specified object needs to update
	virtual void OnUpdate(float deltaTime);

	//called when this object needs to draw
	virtual void OnDraw();

public:
	//set default values for data members
	GameObject();

	static GameObject* getRoot();
	static void setRoot(GameObject* go);

	//set new parent for this object and/or unassign it from its parent
	void SetParent(GameObject* parent);

	//get the current parent
	GameObject* GetParent();

	//get the current parent - const
	const GameObject* GetParent() const;

	//get a child at a specified index from its vector of children
	GameObject* GetChild(size_t childIndex);

	//const above
	const GameObject* GetChild(size_t childIndex) const;


	//Updates this object and all of its children
	void Update(float deltaTime);
	//draws this object and children
	void Draw();

	MathClasses::Vector3 GetLocalPosition() const;
	void SetLocalPosition(MathClasses::Vector3 newPosition);
	void SetLocalPosition(float newX, float newY);

	//get worldpos
	MathClasses::Vector3 GetWorldPosition() const;

	float GetLocalRotation() const;
	void SetLocalRotation(float newRotation);

	//Get worldrot
	float GetWorldRotation() const;

	MathClasses::Vector3 GetLocalScale() const;
	void SetLocalScale(MathClasses::Vector3 newScale);
	void SetLocalScale(float newX, float newY);

	//get worldscale
	MathClasses::Vector3 GetWorldScale() const;

	//get direction it is facing
	MathClasses::Vector3 GetForward() const;

	MathClasses::Matrix3 GetLocalMatrix() const;
	MathClasses::Matrix3 GetWorldMatrix() const;

	//move locally on the x and y axis - z is untouched
	void Translate(float x, float y);
	//move locally on the x, y and z axes
	void Translate(MathClasses::Vector3 translation);

	//rotate locally by a given number of radians
	void Rotate(float radians);

	//scale locally on the x and y axis
	void Scale(float x, float y);

	//scale vec3
	void Scale(MathClasses::Vector3 scalar);

	void Destroy();


	//collider functions
	Collider* m_collider = nullptr;

	virtual void OnCollision();

	void GetColliders(std::vector<Collider*>& GC);
};

