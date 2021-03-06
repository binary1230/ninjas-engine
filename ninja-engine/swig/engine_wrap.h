/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 3.0.9
 *
 * This file is not intended to be easily readable and contains a number of
 * coding conventions designed to improve portability and efficiency. Do not make
 * changes to this file unless you know what you are doing--modify the SWIG
 * interface file instead.
 * ----------------------------------------------------------------------------- */

#ifndef SWIG_engine_WRAP_H_
#define SWIG_engine_WRAP_H_

class SwigDirector_EditorBaseUI : public EditorBaseUI, public Swig::Director {

public:
    SwigDirector_EditorBaseUI();
    virtual void OnObjectsChanged();
    virtual void OnSelectionChanged();
    virtual void OnSelectedObjectMoved();
    virtual ~SwigDirector_EditorBaseUI();

    typedef void (SWIGSTDCALL* SWIG_Callback0_t)();
    typedef void (SWIGSTDCALL* SWIG_Callback1_t)();
    typedef void (SWIGSTDCALL* SWIG_Callback2_t)();
    void swig_connect_director(SWIG_Callback0_t callbackOnObjectsChanged, SWIG_Callback1_t callbackOnSelectionChanged, SWIG_Callback2_t callbackOnSelectedObjectMoved);

private:
    SWIG_Callback0_t swig_callbackOnObjectsChanged;
    SWIG_Callback1_t swig_callbackOnSelectionChanged;
    SWIG_Callback2_t swig_callbackOnSelectedObjectMoved;
    void swig_init_callbacks();
};


#endif
