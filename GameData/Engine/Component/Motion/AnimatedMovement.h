#ifndef ENFUSION_ANIMATEDMOVEMENT_H
#define ENFUSION_ANIMATEDMOVEMENT_H

#include "../Component.h"
#include "../Anim/AnimatedSprite.h"

#define speed_vert speed * 0.9f
#define speed_horz speed
#define speed_diag speed * 0.75f

struct MovementStatus
{
    bool up    = false;
    bool down  = false;
    bool left  = false;
    bool right = false;
};

enum AnimState
{
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class AnimatedMovement : public Component {

public:
    AnimatedMovement(bool hasCollider = false, float speed = 425.0f);

    void initialize()                       override;
    void update(sf::Time tickRate)          override;
    void handleInput(sf::Keyboard::Key key) override;
    void render(sf::RenderWindow* window)   override;

    void setMoving(bool b) { moving = b; }
    inline bool isMoving() { return moving; }
    inline sf::FloatRect* collider() { return &m_colliderRect; }

private:
    float speed;

    sf::Sprite* characterSprite;

    AnimState currentState = AnimState::DOWN;
    MovementStatus st;

    void checkAnimState();
    void switchAnimState(int frame = 1);
    void animate();
    int getRow();

    // animation related
    int   currentFrame    = 1;
    float currAnimTime    = 0.0f;
    float animThreshhold  = 0.175f;

    bool moving    = false;
    bool sprinting = false;

    bool          m_hasCollider;
    sf::FloatRect m_colliderRect;

#if DEBUG_MOVEMENT_SHOW_COLLIDERS == 1
    sf::RectangleShape c_test_rect;
#endif

};


#endif //ENFUSION_ANIMATEDMOVEMENT_H
