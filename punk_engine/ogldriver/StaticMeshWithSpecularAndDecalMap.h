/*
	File: StaticMeshWithSpecularAndDecalMap.h"
	Author: Abramov Nickolai
	Description: Contains a class to represent a geometry
		data of static mesh with multitexture support. for
		drawing it use register combiner, that's cool
*/
#ifndef _H_STATIC_MESH_WITH_SPECULAR_AND_DECAL_MAP
#define _H_STATIC_MESH_WITH_SPECULAR_AND_DECAL_MAP

class StaticMeshWithSpecularAndDecalMap
{
public:
	StaticMeshWithSpecularAndDecalMap(int vCount, int fCount, float* v, float* t, float* n, unsigned short* i);
	~StaticMeshWithSpecularAndDecalMap();
	GLuint m_normalizationCubeMap;
	GLuint m_bumpMap;
	GLuint m_decalMap;
	float m_eye[3];
	float m_lightPos[3];
	float m_lightColor[4];
	float m_ambientColor[4];
	int m_vertexCount;	
	int m_indexCount;
	float* m_vertex;
	float* m_texture;
	float* m_lightVector;
	float* m_normals;
	float* m_tangent;
	float* m_binormal;
	unsigned short* m_index;
	void Draw();
	void SetNormalizationMap(GLuint textureId);
	void SetBumpMap(GLuint textureId);
	void SetLightPos(float x, float y, float z);
	void SetLightColor(const float* color);
	void SetAmbientColor(const float* color);
	void SetEye(const float* eye);
	void SetDecalMap(GLuint decal);
	static StaticMeshWithSpecularAndDecalMap* CreateFromFile(const char* filename);
private:
	void InternalDraw_v1();
	void InternalDraw_v2();	
};

#endif //	_H_STATIC_MESH_WITH_SPECULAR_AND_DECAL_MAP