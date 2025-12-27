package Hausaufgabenprojekt_Java;

/*
 * Name: Zhinoo Zobairi
 * Matrikelnummer: 823529
 */

import java.util.List;
import java.util.Queue;
import java.util.Set;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.LinkedList;

interface Taggable<T> { // interface does not define where or how the tag is stored. Interfaces dictate class contracts, and classes dictate object behaviors. The interface Taggable<T> only cares about one thing: The ability to set and get a tag of type T. It does not care if the implementing class has: more fields, more type parameters, more logic.
    void setTag(T tag); // setter: It assigns a tag (of type T) to the object. When you call it, you pass in the tag you want to attach.
    T getTag();         // getter: It returns the current tag (of type T) that’s stored on the object. When you call it, you receive the tag back.
}
public class Node<TagType, InfoType> implements Taggable<TagType> { // “A Node where TagType is the type of the name (The type of the thing you store as the tag inside this interface), and InfoType is the type of the extra info.” 
    private TagType tag;  // Only Node class can directly access
    private InfoType info;
    private List<Node<TagType, InfoType>> neighbors;     // “A private list that holds Node objects, where each Node has the same T and U types as this Node.”

    public Node(TagType tag, InfoType info) { // It takes two parameters: one for the tag, one for the info.
    this.tag = tag;
    this.info = info;
    this.neighbors = new ArrayList<>(); // ArrayList<> is a concrete class, we can new it.
    }

    public void setTag(TagType tag) {
    this.tag = tag;
    }

    public TagType getTag() {
        return this.tag;
    }

    public InfoType getInfo() {
    return this.info;
    }

    public void setInfo(InfoType info) {
    this.info = info;
    }
    public void connect(Node<TagType, InfoType> node) {
    if (!this.neighbors.contains(node)) {
        this.neighbors.add(node);
        node.neighbors.add(this); 
    }
    }

    public void disconnect(Node<TagType, InfoType> node) {
        if (this.neighbors.contains(node)) {
            this.neighbors.remove(node);
            node.neighbors.remove(this); 
        }
    }

    public List<Node<TagType, InfoType>> traverse() {
    List<Node<TagType, InfoType>> visitedNodes = new ArrayList<>();
    Queue<Node<TagType, InfoType>> queue = new LinkedList<>();
    Set<Node<TagType, InfoType>> visitedSet = new HashSet<>();

    queue.add(this);
    visitedSet.add(this);

    while (!queue.isEmpty()) {
        Node<TagType, InfoType> current = queue.poll();
        visitedNodes.add(current);

        for (Node<TagType, InfoType> neighbor : current.neighbors) {
            if (!visitedSet.contains(neighbor)) {
                queue.add(neighbor);
                visitedSet.add(neighbor);
            }
        }
    }
    return visitedNodes;
    }

    public void printNode() {
    System.out.println("Tag: " + this.tag + ", Info: " + this.info);
    }

    public void printNeighbours() {
        System.out.print("Neighbours of " + this.tag + ": ");
        for (Node<TagType, InfoType> neighbor : neighbors) {
            System.out.print(neighbor.tag + " ");
        }
        System.out.println();
    }

    public void printNetwork() {
        System.out.println("Network:");
        for (Node<TagType, InfoType> node : traverse()) {
            node.printNode();
        }
    }

}
