//функции для конвертирования компонент в соответствующие дочернии классы
Render *make_Render(GameObject *obj, Application& app) {
    ComponentType *CT_obj = obj->getComponent("Render");
    Render *R_obj = dynamic_cast<Render *>(CT_obj);
    app.R_Objects.push_back(R_obj);
    return R_obj;
}

Collider *make_Collider(GameObject *obj, Application& app) {
    ComponentType *CT_obj = obj->getComponent("Collider");
    Collider *C_obj = dynamic_cast<Collider *>(CT_obj);
    app.C_Objects.push_back(C_obj);
    return C_obj;
}

RigidBody *make_RigidBody(GameObject *obj, Application& app) {
    ComponentType *CT_obj = obj->getComponent("Rigid_Body");
    RigidBody *RB_obj = dynamic_cast<RigidBody *>(CT_obj);
    app.RB_Objects.push_back(RB_obj);
    return RB_obj;
}
