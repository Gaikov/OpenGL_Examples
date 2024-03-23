//
// Created by Roman on 3/23/2024.
//

#ifndef GL00_TRIANGLE_BASEEXAMPLE_H
#define GL00_TRIANGLE_BASEEXAMPLE_H

class BaseExample {
public:
    virtual ~BaseExample() = default;
    virtual bool Init() = 0;
    virtual void Update(float deltaTime) = 0;
};


#endif //GL00_TRIANGLE_BASEEXAMPLE_H
