# Advanced Caesar Cipher Encoder

A basic encoder that accepts user input and encodes it using a more complex version of the Caesar Cipher. This encoder applies a different shift to each character based on a user-provided encoding key.

## How to Use

1. **Choose an Encoding Key**: 
   - Input a string of numbers prefixed with either `+e` (for addition) or `-e` (for subtraction) to set the encoding key.
   
2. **Enter Your Text**:
   - Type any text you want to encode. The encoder will immediately apply the encoding based on your specified key.

## How to Run

1. **Compile the Program**:
   - Run the following command in the terminal to compile:
     ```bash
     make encoder
     ```

2. **Run the Program**:
   - Use the following syntax to run the encoder:
     ```bash
     ./encoder [+D | -D] [+e{key} | -e{key}] [-Ifilename] [-Ofilename]
     ```
     - `+D / -D`: Toggle debug mode on/off (default is off).
     - `+e{key} / -e{key}`: Set the encoding key for addition or subtraction.
     - `-Ifilename`: Specify an input file (default: `stdin`).
     - `-Ofilename`: Specify an output file (default: `stdout`).

3. **Entering Text to Encode**:
   - If you do not specify an input file, you can type the text you want to encode directly into the program’s shell, and it will output the encrypted text instantly.

### Example

To run an encoding with the key `+e12345`:

```bash
make encoder
./encoder +e12345
Hello!
Hgopt!
```


-e2024
Fiph tji Bgrpy mp aswr Mgnk!
