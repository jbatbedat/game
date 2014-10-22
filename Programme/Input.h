#ifndef INPUT_H
#define INPUT_H


//Classe qui va stocker les états des inputs
//cf event.cpp
class Input
{
    public:
    Input();

    void setm_down(bool a);
    void setm_up(bool a);
    void setm_left(bool a);
    void setm_right(bool a);
    void setm_space(bool a);
    void setm_quit(bool a);
    bool getm_space();
    bool getm_up();
    bool getm_quit();
    bool getm_down();
    bool getm_left();
    bool getm_right();
    bool m_left;
    bool m_right;
    bool m_up;
    bool m_down;
    bool m_space;
    bool m_quit;

};

#endif // INPUT_H
