#pragma once

#include <string>
#include <vector>
#include <assert.h>
#include <memory>
#include <utility>
#include "Vec2.h"

//extra warnings
// /wo4191 – unsafe conversion from ‘type of expression’ to ‘type required’
// /wo4242 – conversion from ‘type1’ to ‘type2’, possible loss of data
// /wo4263 – member function does not override any base class virtual member function
// /wo4264 – no override available for virtual member function from base ‘class’; function is hidden
// /wo4265 – class has virtual functions, but destructor is not virtual
// /wo4266 – no override available for virtual member function from base ‘type’; function is hidden
// /wo4302 – truncation from ‘type 1’ to ‘type 2’
// /wo4826 – conversion from ‘type1’ to ‘type2’ is sign - extended.This may cause unexpected runtime behavior
// /wo4905 – wide string literal cast to ‘LPSTR’
// /wo4906 – string literal cast to ‘LPWSTR’
// /wo4928 – illegal copy - initialization; more than one user - defined conversion has been implicitly applied

//wo4191 /wo4242 /wo4263 /wo4264 /wo4265 /wo4266 /wo4302 /wo4826 /wo4905 /wo4906 /wo4928
