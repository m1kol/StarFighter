
void make_Render(GameObject *obj, Application& app) {
    for (int i = 0; i < obj->components.size(); i++) {
        ComponentType *a;
        a = obj->getComponent(i);
        if (Render *R_obj = dynamic_cast<Render *>(a)) {
            std::cout << "Sheet"<< "\n";
            app.R_Objects.push_back(R_obj);
        }
    }
}

void make_Collider(GameObject *obj, Application& app) {
    for (int i = 0; i < obj->components.size(); i++) {
        ComponentType *a;
        a = obj->getComponent(i);
        if (Collider *C_obj = dynamic_cast<Collider *>(a)) {
            std::cout << "Sheet"<< "\n";
            app.C_Objects.push_back(C_obj);
        }
    }
}

GameObject* create_R_Object(std::string File, float X, float Y, float W, float H, Application& app){
    GameObject Object;
    Render Render_Object(File, X, Y, W, H);
    Object.addComponent(Render_Object);
    make_Render(&Object, app );
    return &Object;
}
//
//GameObject* create_R_and_C_Object(std::string File, float X, float Y, float W, float H) {
//    GameObject Object;
//    Render Render_Object(File, X, Y, W, H);
//    Object.addComponent(Render_Object);
//    Collider Collider_Object(X, Y, W, H);
//    Object.addComponent(Collider_Object);
//    return &Object;
//}
