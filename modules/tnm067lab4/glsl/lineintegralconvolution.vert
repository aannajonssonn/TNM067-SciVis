out vec3 texCoord_;

void main() {
    texCoord_ = in_TexCoord;
    gl_Position = in_Vertex;
}
