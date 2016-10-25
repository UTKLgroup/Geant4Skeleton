#include "RNGWrapper.hh"

template CLHEP::HepRandomEngine* RNGWrapper<CLHEP::HepRandomEngine>::m_obj;

template double (CLHEP::HepRandomEngine::*RNGWrapper<CLHEP::HepRandomEngine>::m_func)(void);
