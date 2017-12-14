#ifndef GAMEENGINE_FUNCTEMPLATE_H
#define GAMEENGINE_FUNCTEMPLATE_H

namespace gameEngine{

    template <typename CLASS>
    class FuncTemplate{
    public:
        FuncTemplate(CLASS *c, void (CLASS::*mf)()) : obj(c), memberFunc(mf){};

        void perform(){
            (obj->*memberFunc)();
        }

    private:
        CLASS *obj;
        void (CLASS::*memberFunc)();
    };
}

#endif //GAMEENGINE_FUNCTEMPLATE_H
