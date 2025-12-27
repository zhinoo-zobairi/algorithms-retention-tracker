package Hausaufgabenprojekt_Java;

import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        Node<String, java.util.List<Integer>> A = new Node<>("A", Arrays.asList(1,2,3));
        Node<String, java.util.List<Integer>> B = new Node<>("B", Arrays.asList(4,5,6));
        Node<String, java.util.List<Integer>> C = new Node<>("C", Arrays.asList(7,8,9));
        Node<String, java.util.List<Integer>> D = new Node<>("D", Arrays.asList(10,11,12));
        Node<String, java.util.List<Integer>> E = new Node<>("E", Arrays.asList(13,14,15));
        Node<String, java.util.List<Integer>> F = new Node<>("F", Arrays.asList(16,17,18));
        Node<String, java.util.List<Integer>> G = new Node<>("G", Arrays.asList(19,20,21));

        A.connect(F);
        A.connect(G);
        A.connect(B);
        F.connect(C);
        C.connect(D);
        D.connect(E);

        System.out.println("Graph 1:");
        A.printNetwork();

        A.setTag("A2");
        A.setInfo(Arrays.asList(23,24,25));
        G.setTag("G2");
        G.setInfo(Arrays.asList(19,20,21,22));
        B.setTag("B2");
        B.setInfo(Arrays.asList(5,6));
        System.out.println("\nGraph 2:");
        A.printNetwork();

        System.out.println("\nSomit wurden beide Netzwerke erfolgreich dargestellt!!");
    }
}