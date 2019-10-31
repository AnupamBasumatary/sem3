import java.util.Scanner;

class customException extends Exception
{
	String s=" ";
  public customException(String message)
  {
    super(message);
	s=message;
  }
  public String toString()
  {
	  return s;
  }
}
class DoublyLinkedList<T>
{
	class Node
	{
		T data;
		Node next, prev;

		Node(T data)
		{
			this.data = data;
			next = prev = null; //ofcourse
		}
	}

	Node head, tail;

	void insertLast(T data)
	{
		if(head == null)
		{
			head = new Node(data);
			tail = head;
		}

		else
		{
			Node node = new Node(data);
			tail.next = node;
			node.prev = tail;
			tail = node;
		}
	}

	void insertFirst(T data)
	{
		if(head == null)
		{
			head = new Node(data);
			tail = head;
		}

		else
		{
			Node node = new Node(data);
			node.next = head;
			head.prev = node;
			head = node;
		}
	}

	void insertIndex(T data, int index)
	{
		if(index == 0)
		{
			insertFirst(data);
			return;
		}

		Node node = new Node(data), temp = head;
		int i = 0;

		while(i != index - 1)
		{
			if(temp.next == null)
			{
				System.out.println("\nInvalid index");
				return;
			}
			temp = temp.next;
			i++;
		}

		if(temp == tail)
			insertLast(data);

		else
		{
			node.next = temp.next;
			node.prev = temp;
			temp.next = node;
		}
	}

	void deleteFirst() throws customException
	{
		if(head == null)
			throw (new customException("List is Empty"));
		else
			head = head.next;
	}

	void deleteLast() throws customException
	{
		if(head == null)
			throw (new customException("List is Empty"));
		else
		{
			tail = tail.prev;
			tail.next = null;
		}
	}

	// void deleteIndex(int index)
	// {
	// 	if(index == 0)
	// 	{
	// 		deleteFirst();
	// 		return;
	// 	}

	// 	int i = 0;
	// 	Node temp = head;

	// 	while(i != index - 1)
	// 	{
	// 		temp = temp.next;
	// 		if(temp.next == null)
	// 		{
	// 			System.out.println("Invalid Index");
	// 			return;
	// 		}
	// 		i++;
	// 	}

	// 	if(temp.next == tail)
	// 	{
	// 		temp.next = null;
	// 		tail = temp;
	// 	}
	// 	else
	// 	{
	// 		temp.next = temp.next.next;
	// 		temp.next.prev = temp;
	// 	}
	// }

	int search(T data)
	{
		Node temp = head;

		int index = 0;
		while(temp != null)
		{
			if(temp.data.equals(data))
				return index;

			index++;
			temp = temp.next;
		}
		return -1;
	}

	void reverse()
	{
		Node temp = head;

		while(temp != null)
		{
			Node n = temp.prev;
			temp.prev = temp.next;
			temp.next = n;

			temp = temp.prev;
		}

		temp = head;
		head = tail;
		tail = temp;
	}

	void show() throws customException
	{
		Node temp = head;
		if(temp==null)
			throw (new customException("List is Empty"));
		while(temp != null)
		{
			System.out.print(temp.data + " ");
			temp = temp.next;
		}
		System.out.println();
	}
}

class P11
{
	public static void main(String args[])
	{
		Scanner read = new Scanner(System.in);

		DoublyLinkedList<Integer> list = new DoublyLinkedList<>();
		int option;

		do
		{
			System.out.println("\n1.Insert in Start\n2.Insert in End\n3.Insert in index\n4.Delete First\n5.Delete Last\n6.Delete Index\n7.Search\n8.Reverse");

			option = read.nextInt();
			try{
				switch(option)
				{
					case 1:
						System.out.print("\nEnter the element: ");
						list.insertFirst(read.nextInt());
						list.show();
					break;

					case 2:
						System.out.print("\nEnter the element: ");
						list.insertLast(read.nextInt());
						list.show();
					break;

					case 3:
						System.out.print("\nEnter the element, index: ");
						list.insertIndex(read.nextInt(), read.nextInt());
						list.show();
					break;

					case 4:
						list.deleteFirst();
						list.show();
					break;

					case 5:
						list.deleteLast();
						list.show();
					break;

					case 6:
						// System.out.print("\nEnter the index: ");
						// list.deleteIndex(read.nextInt());
						// list.show();
					break;

					case 7:
						System.out.println("\nEnter the element: ");
						int index = list.search(read.nextInt());
						
						if(index == -1)
							System.out.println("Not Found");

						else
							System.out.println("Found at" + index);
					break;

					case 8:
						list.reverse();
						list.show();

					break;

				}
			}
			catch(customException e)
				{
					System.out.println(e);
				}
		}
		while(option != 0);
	}
}
