#ifndef MATERIAL_H
#define MATERIAL_H

class Material {
    public:
        Material();
        Material(int type);
        int getType();
    private:
        int type;
};

#endif