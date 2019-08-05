# Optimized-Plotter-CNC
I saw this project from [instructables.com](https://www.instructables.com/id/Mini-CNC-Machine-Arduino-Based-Adafruit-Driver-Mot/) and it seems like the code doesn't work as expected so I optimized it.

### Here're some details of what I've changed:
1. Change step type from MICROSTEP to INTERLEAVE for better toque.
```c
    char STEP = INTERLEAVE
```
2. Change data type to long because Int couldn't handle it.
```c
    x1 = (long)(x1*StepsPerMillimeterX);
    y1 = (long)(y1*StepsPerMillimeterY);
```
3. Reset pen settings to this
```c
    float StepInc = 1;
    int StepDelay = 1;
    int LineDelay = 0;
    int penDelay = 40;
``` 
Contributing
------------

We welcome all contributions by sending PR to this repository.

Need Help ?
-----------

If you need help with anything just ask me via [Email](mailto:witjarukit@gmail.com) or create an issue

