/**
 * Project: MacroPad Custom
 * Author: Arnold Nunez
 * Date: 7/13/2024
 */

 #ifndef CONTEXT_H
 #define CONTEXT_H

 #include <string>

/**
 * Class representing the macropad context. A context is the
 * representation of a runtime state or environment which
 * influences the macros that can applied.
 */
class Context
{
  /**
   * Constructor
   */
  Context();

  /**
   * Destructor
   */
  ~Context();

  /**
   * Copy constructor (disabled)
   */
  Context(const Context&) = delete;

  /**
   * Setter for the name
   */
  void SetName(const std::string& name);

  /**
   * Getter for the name
   */
  std::string GetName() const;

private:

  // Name for the context
  std::string mName;

  // Unique id for the context
  unsigned short mId;
};

 #endif // CONTEXT_H