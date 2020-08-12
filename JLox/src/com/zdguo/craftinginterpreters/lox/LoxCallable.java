package com.zdguo.craftinginterpreters.lox;

import java.util.List;

interface LoxCallable {
    int arity(); // the number of arguments expected
    Object call(Interpreter interpreter, List<Object> arguments);
}
