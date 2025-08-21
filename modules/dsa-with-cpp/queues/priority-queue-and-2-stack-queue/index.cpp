/**
 * Priority Queue
 *
 * 1. Limited Set of priorties: Each element can be a part of a limited subset
 * of priorties. For implementing, we create n number of queues and add it to
 * it's own priority queue. While dequeuing, we first check in the queue with
 * the highest priority, then the next and so on.
 *
 * 2. Element Priority: The element itself is the priority. Priority is not
 * restricted to a limited set. If we want to implement only using arrays, then
 * there are only 2 ways. Insert in the same order and delete max prioroty by
 * searching OR insert in order of priority and delete last element. Both of
 * them are not optimal.
 *
 * Queue using 2 stacks:
 *
 * 1. Enqueue: Always add elements to stack1.
 * 2. Dequeue: If stack2 is empty, first pop eveyrhting oit of stack1 and add it
 * to stack2 and then pop from stack2. If stack is emoty, pop from stack2.
 */
