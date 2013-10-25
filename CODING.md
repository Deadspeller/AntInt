Coding guideline
============================

Preface
-------
This document is written using the
[markdown syntax](http://daringfireball.net/projects/markdown/syntax) and can
be converted to a nicely formatted HTML document. To do this you will
have to install markdown, e.g. on Debian / Ubuntu:

`$ sudo apt-get install markdown`

Afterwards generating a HTML document is as easy as executing:

`$ markdown CODING.md > CODING.html`

Introduction
------------
This document describes the coding guidelines for writing C++ code.

Please note that deviating from this guideline will result in an
**immediate rejection** of your submitted code.

1. File naming conventions
--------------------------
* All source and header files must be created in lowercase letters.
* Header files need to have **.h** as file extension.
* C++ Source files need to have **.cpp** as file extension.
* C Source files need to have **.c** as file extension.
* Files containing templates must have **.tcc** as file extension.
* All source and header files must be named after the main class they
  contain, e.g. ClassXy -> *classxy.h, classxy.cpp, classxy.tcc*
* Private header files should be named after the main class they
  are used by with `_private.h` as suffix, e.g.
  ClassXy -> needs ClassXyPrivate -> declaration in *classxy_private.h*

2. Implementation details
-------------------------
* Class names must start with an uppercase letter
* Method / function names are starting with a lowercase letter
* Class attributes are starting with the `m_` prefix
* Class attribute *names* are starting in lowercase, e.g. `m_someMember`
* Classes, methods, functions and variables are to be named in
  [Camel-Case](http://de.wikipedia.org/wiki/Camel_Case)
* Do **not** use the prefix `get` for methods returning values
* Classes that will be derived from should have a virtual destructor
  (except when it can be guranteed that derived objects are not deleted by
  a base class pointer)
* To guarantee a stable ABI consider putting private member variables
  in a private structure ([pimpl idiom](http://c2.com/cgi/wiki?PimplIdiom)).
  **Please keep in mind that the pimpl *must* be deleted in destructor to
  prevent leakage!** This can easily be managed by utilising a smart pointer
  for the pimpl (e.g. shared_ptr or unique_ptr).
* For complex types exposed by the interface the usage of type definitions
  is advised (e.g. instead of using `shared_ptr<Foo>` create a
  `typedef shared_ptr<Foo> FooPtr` and return `FooPtr`).
* When possible constant references to complex types instead of a copy
  are to be passed to methods and functions
  (e.g. instead of using `foo(Bar baz)` pass `foo(const Bar &baz)`)
* Methods not altering internal values of a class or struct must
  have a CV-qualifier (this most likely applies to many functions
  returning values).
* Avoid usage of comparison and assignment in a single instruction (e.g. do
  **never** use *if ((err = open("foo")) < 0){}*)

3. Structure
------------
### 3.1 Directories / files
* Implementation, templates and declarations must be strictly
  separated (in corresponding .c, .cpp, .h, .tcc files).
* All files must be placed in their correct module subfolder of the
  source tree.
* For each new module a new subfolder needs to be created.

### 3.2 C++ Namespaces
* Every declaration / implementation must be wrapped in its correct
  module specific namespace.
* For each new module a new namespace (inside the `cs` namespace) needs
  to be created.

### 3.3 Classes
* Class members need to be ordered in the following manner:
    1. public > protected > private
    2. methods > attributes
    3. Constructors and Destructors need to appear at the top of
       the section they appear in.

### 3.4 Text
* The maximum text width in all files is **100 characters**.
* Tabulator characters need to be expanded to space characters.
* The indentation of code blocks is a multiple of 4 space characters.
* Whitespace at the end of lines or at the end of a file *always*
  leads to rejection of patches.

4. Documentation
----------------
* **Every** public or protected interface must be documented using
  Doxygen tags.
* **Every** parameter and return value of public and protected
  methods or functions must be documented.
* The direction of parameters (out / in) must be specified along with
  the @param tag (e.g. `@param[in] foo [...]` or
  `@param[out] bar [...]`).
* Doxygen tags must start with a `@` character
* Classes must be documented in the following fashion:  
  `/**`  
  ` * @class ClassName headerfile.h globalheaderfile.h`  
  ` * @brief Brief description`  
  ` *`  
  ` * Long description`  
  ` *`  
  ` * @author Author Name <author email address>`  
  ` * @since version`  
  ` * @ingroup module_name`  
  ` */`  
* The documentation must explain the purpose and correct usage of the
  interface. Example usage code snippets are a good way to achieve this
  for complex interfaces.
* For each new module a corresponding Doxygen group needs to be created.
  This group is labeled like the module name and its declaration resides
  in a `<module_name>.dox` file in the top level source directory of the
  module.

Last words
----------
Following these simple rules is a warrant for lower frustration due
to constant rejections on the library maintainer / submitter and
patch reviewer sides. Apart from that it ensures a constant and good
code quality and readability and improves the lifes for all of us :).
