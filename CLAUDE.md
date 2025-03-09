# IntergintSystems VCV Rack Plugin - Developer Guide

## Build Commands
- Build plugin: `make`
- Clean build: `make clean`
- Create distribution package: `make dist`
- Install plugin to Rack: `make install`

## Development Guidelines

### Code Structure
- Modules are defined in separate .cpp/.hpp files in `src/` directory
- Register new modules in `plugin.cpp` using `p->addModel(modelYourModule);`
- Unit tests use Catch2 framework in the tests/ directory

### Coding Style
- Use C++11 standard
- Follow VCV Rack API conventions
- Use 2-space indentation
- Prefix class member variables with `m_`
- Use camelCase for methods and variables

### Error Handling
- Use assertions for developer errors
- Validate user inputs with bounds checking
- Avoid exceptions in real-time audio processing

### Module Development
- Keep DSP code separate from UI code
- Implement `process()` methods efficiently
- Initialize all member variables in constructors
- Use VCV standards for parameter ranges (0-1)
- Write unit tests for all non-UI functionality

## Panel Design Guidelines

### Setup
- Set document units to "mm" (not px)
- Set height to 128.5 mm and width to a multiple of 5.08 mm (1 HP)

### Design Recommendations
- Design panels as if designing hardware
- Ensure adequate space between controls for thumb access
- Use inverted background for output ports
- Make labels succinct and clear
- Match text sizes and graphical density of VCV modules
- Ensure text is readable at 100% on non-high-DPI monitors

### SVG Requirements
- Convert all text to paths (Path > Object to Path in Inkscape)
- Avoid complex gradients (simple two-color linear gradients only)
- No CSS (except fill-* and stroke-* properties in inline style attributes)

### Component Placement
- Create a separate "components" layer for placeholders
- Use specific colors for component types:
  - Param: red (#ff0000)
  - Input: green (#00ff00)
  - Output: blue (#0000ff)
  - Light: magenta (#ff00ff)
  - Custom widgets: yellow (#ffff00)
- Use circle tool (F5) for center positioning or rectangle tool (F4) for top-left positioning
- Name components in Object Properties panel to generate C++ names
- Hide components layer before saving to res/<module slug>.svg

### Panel to Code Generation
- Run `<Rack SDK>/helper.py createmodule <module slug> res/<module slug>.svg src/<module slug>.cpp`
