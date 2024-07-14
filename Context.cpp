/**
 * Project: MacroPad Custom
 * Author: Arnold Nunez
 * Date: 7/13/2024
 */

 #include "Context.h"

//-----
 Context::Context() : mName(""), mId(0)
 {

 }

 //-----
 Context::~Context()
 {

 }

//-----
void Context::SetName(const std::string& name)
{
  mName = name;
}

//-----
std::string Context::GetName() const
{
  return mName;
}