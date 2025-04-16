so here it is.

--- 
## Triangles.h

has two `struct` one for general **Points** in decart coordinate system and other utilizes **Points** one and does a **triangle**. Ith has these methods:
- `bool isDegenerate() const;` - to chek degeneracy of triangle
- `double area() const; // USE HERON` - to calculate area (wow)
- `enum PointLocation` - used to easy my life
- `PointLocation contains(const Point &P) const;` - is the star of the show

```
bugagashke
```

here is random code from lab (not even OOP LOL ITS DISCRETE MATH HAHAHAHAHAHHAHAHA)

``` java title:I-Know-How-To-Use-MarkDown
public static String infixToPostfix(String expression) {  
    Stack<String> operatorStack = new Stack<>();  
    StringBuilder postfix = new StringBuilder();  
  
    String[] tokens = expression.split(" ");  
  
    for (String token : tokens) {  
        if (isOperand(token)) {  
            postfix.append(token).append(" ");  
        } else if (isOperator(token)) {  
            while (!operatorStack.isEmpty() &&  
                    precedence(operatorStack.peek()) >= precedence(token)) {  
                postfix.append(operatorStack.pop()).append(" ");  
            }            operatorStack.push(token);  
        } else if (token.equals("(")) {  
            operatorStack.push(token);  
        } else if (token.equals(")")) {  
            while (!operatorStack.isEmpty() && !operatorStack.peek().equals("(")) {  
                postfix.append(operatorStack.pop()).append(" ");  
            }            operatorStack.pop(); // Remove '('  
        }  
    }
```