#ifndef CTRANSFORM_H_
#define CTRANSFORM_H_
#include "../Mtx44.h"
#include "../Vector3.h"

class CTransform
{
public:
	CTransform();
	virtual ~CTransform();

	inline void SetTranslate(const float& x, const float& y, const float& z) {
		Mtx44 tempMtx;
		tempMtx.SetToTranslation(x, y, z);
		t_Mtx = t_Mtx * tempMtx;
	};
	inline void SetTranslate(const Vector3& t) {
		Mtx44 tempMtx;
		tempMtx.SetToTranslation(t.x, t.y, t.z);
		t_Mtx = t_Mtx * tempMtx;
	};

	inline void SetRotate(const float& r, const float& x, const float& y, const float& z) {
		Mtx44 tempMtx;
		tempMtx.SetToRotation(r, x, y, z);
		t_Mtx = t_Mtx * tempMtx;
	};
	inline void SetRotate(const Vector3& r) {
		Mtx44 tempMtx;
		tempMtx.SetToRotation(r.y, 0, 1, 0);
		tempMtx.SetToRotation(r.x, 1, 0, 0);
		tempMtx.SetToRotation(r.z, 0, 0, 1);
		t_Mtx = t_Mtx * tempMtx;
	};

	inline void SetScale(const float& x, const float& y, const float& z) {
		Mtx44 tempMtx;
		tempMtx.SetToScale(x, y, z);
		t_Mtx = t_Mtx * tempMtx;
	};
	inline void SetScale(const Vector3& s) {
		Mtx44 tempMtx;
		tempMtx.SetToScale(s.x, s.y, s.z);
		t_Mtx = t_Mtx * tempMtx;
	};

	inline Vector3 GetLocalTranslate() const {
		return Vector3(t_Mtx.a[12], t_Mtx.a[13], t_Mtx.a[14]);
	};
	inline Vector3 GetRotate() const {
		float a, b; Vector3 result;
		a = acos(t_Mtx.a[5]);
		b = asin(-t_Mtx.a[9]);
		if (abs(a - b) < Math::EPSILON)
			result.x = b;
		a = acos(t_Mtx.a[0]);
		b = asin(t_Mtx.a[8]);
		if (abs(a - b) < Math::EPSILON)
			result.y = b;
		a = acos(t_Mtx.a[0]);
		b = asin(-t_Mtx.a[4]);
		if (abs(a - b) < Math::EPSILON)
			result.z = b;
		return result;
	};
	inline Vector3 GetScale() const {
		return Vector3(t_Mtx.a[0], t_Mtx.a[5], t_Mtx.a[10]);
	};
	inline Mtx44 GetTransformMatrix() const { 
		return t_Mtx; 
	};

protected:
private:
	Mtx44 t_Mtx;

};

#endif