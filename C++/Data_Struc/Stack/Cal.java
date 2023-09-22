import java.io.*;
import java.util.Stack;
import java.lang.String;
import java.lang.Math;
public class Cal{
		public static int order(char operator){
		switch(operator){
			case '+':
			case '-':
				return 2;
			case '*':
			case '/':
			case '%':
				return 3;
			case '#':
				return -5;//return negative value to show right
			case '^':
				return -4;
		}
		return -1;
	}
	public static String toPostfix(String exp) throws Exception{
		StringBuilder result = new StringBuilder();
		Stack<Character> stack = new Stack<>(); // stack of operators
		for (int i = 0; i < exp.length(); i++) {
			char c = exp.charAt(i);
			if(c == '=') break;
			if(c == ' ') continue;
			if(Character.isDigit(c)){
				while(Character.isDigit(c)){
					result.append(c);
					i++;
					if(i<exp.length()) c = exp.charAt(i);
					else break;
				}
				result.append(' ');
				i--;
			}
			else if(c == '('){
				stack.push(c);
			}
			else if(c == ')'){
				while(!stack.isEmpty() && stack.peek() != '('){ // pop until meeting first (
					result.append(stack.pop());
					result.append(' ');
				}
				if(!stack.isEmpty() && stack.peek() != '('){ // if no parathenses
					throw new Exception();
				}
				else{ // pop (
					stack.pop();
				}
			}
			else{
				if(order(c) > 0){
					while(!stack.isEmpty() && order(c) <= Math.abs(order(stack.peek()))){ // if left-associative
						result.append(stack.pop());
						result.append(' ');
					}
					stack.push(c);
				}
				else{
					while(!stack.isEmpty() && Math.abs(order(c)) < Math.abs(order(stack.peek()))){ // if right-associative
						result.append(stack.pop());
						result.append(' ');
					}
					stack.push(c);
				}
			}
		}
		while(!stack.isEmpty()){
			if(stack.peek() == '(') {
				throw new Exception();
			}
			result.append(stack.pop());
			result.append(' ');
		}
		return result.toString(); // trim last space
	}
	public static long evaluate(String postString) throws Exception{
		Stack<Long> stack = new Stack<>();
		for (int i = 0; i < postString.length(); i++) {
			char c = postString.charAt(i);
			if(c == ' ') continue;
			if(Character.isDigit(c)){
				long num = 0;
				while(Character.isDigit(c)){
					num = num*10 + (c-'0');
					i++;
					if(i<postString.length()) c = postString.charAt(i);
					else break;
				}i--;
				stack.push(num);
			}
			else if(c == '#'){
				try {
					long num1 = stack.pop();
					stack.push((long)Math.sqrt(num1));
				} catch (Exception e) {
					throw new Exception();
				}
			}
			else{ // binary opreators
				try {
					long num2 = stack.pop();
					long num1 = stack.pop();
					switch(c){
						case '+':
							stack.push(num1+num2);
							break;
						case '-':
							stack.push(num1-num2);
							break;
						case '*':
							stack.push(num1*num2);
							break;
						case '/':
							stack.push(num1/num2);
							break;
						case '^':
							if(num1 == 0 && num2 <0) throw new Exception();
							stack.push((long)(Math.pow(num1, num2)));
							break;

					}
				} catch (Exception e) {
					throw new Exception();
				}
			}

		}
		try {
			if(stack.size() != 1) throw new Exception(); // if stack empty or many left
			return stack.pop();
		} catch (Exception e) {
			throw new Exception();
		}
	}
	public static void main(String args[])
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		while (true)
		{
			try
			{
				String input = br.readLine();
				command(input);
				//break;
			}
			catch (Exception e)
			{
				System.out.println("ERROR");
			}
		}
	}

	private static void command(String input)
	{
		try {
			String postString = toPostfix(input);
			long ans = evaluate(postString);
			//System.out.println(postString);
			System.out.println(ans);
		} catch (Exception e) {
			System.out.println("ERROR");
		};
	}
}
