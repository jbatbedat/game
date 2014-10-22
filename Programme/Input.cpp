#include "Input.h"

Input::Input(): m_down(0), m_up(0), m_left(0), m_right(0), m_space(0), m_quit(0)
{

}

void Input::setm_down(bool a)
{
    m_down=a;
}

void Input::setm_up(bool a)
{
    m_up=a;
}

void Input::setm_left(bool a)
{
    m_left=a;
}

void Input::setm_right(bool a)
{
    m_right=a;
}

void Input::setm_space(bool a)
{
    m_space=a;
}

void Input::setm_quit(bool a)
{
    m_quit=a;
}

bool Input::getm_quit()
{
    return m_quit;
}

bool Input::getm_space()
{
    return m_space;
}

bool Input::getm_left()
{
    return m_left;

}

bool Input::getm_right()
{
    return m_right;
}

bool Input::getm_up()
{
    return m_up;
}

bool Input::getm_down()
{
    return m_down;
}
