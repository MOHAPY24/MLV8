# MLV8 Errorsheet

Errors:
* ID: 1, an endpoint such as `0xFF` or `0xFE` was not found in the given instructions, this is raised to prevent a constant program execution.
* ID: 2, an opcode passed is unkown or invalid, this is raised to prevent pointer freezages and unhandeled execution.