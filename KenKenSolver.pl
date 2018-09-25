% Marian Nguyen
% September 27, 2018
% CECS 424
% Lab 1: Puzzling Prolog

% module used to use 'ins' and 'all_distinct'
:- use_module(library(clpfd)).

% sum_list finds the sum of a list of integers
% sum_list([1,3,5], S) should give S=9
sum_list([], 0).
sum_list([H|T], Sum):- sum_list(T, S2), Sum #= H + S2.

% product_list finds the product of a list of integers
% product_list([3,2,3], M) should give M=18
product_list([], 1).
product_list([H|T], Ans):- product_list(T, M), Ans #= H * M.

% cell_values(Cells, S, Values) translates a list of coordinates into a
% list of vlues at those coordinates.
% Given S whose first row contains the values 2, 1, then
% cell_values([[0,0], [0,1]], S, Values) would give Values = [2,1]
cell_values([], S, []).
cell_values([H|T], S, Values):-

% creates irregular "cages" in KenKen puzzle
cage(mult, 120, [[0,0], [0,1], [1,0], [2,0]]).
cage(div, 2, [[1,1], [2,1]]).
cage(mult, 15, [[3,0], [3,1]]).
cage(sub, 3, [[4,0], [5,0]]).
cage(sub, 1, [[4,1], [4,2]]).
cage(sub, 5, [[5,1], [5,2]]).
cage(mult, 144, [[0,2], [1,2], [1,3], [1,4]]).
cage(sub, 3, [[2,2], [3,2]]).
cage(id, 4, [0,3]).
cage(sub, 4, [[2,3], [2,4]]).
cage(add, 16, [[3,3], [3,4], [4,3], [5,3]]).
cage(add, 6, [[0,4], [0,5]]).
cage(div, 3, [[1,5], [2,5]]).
cage(mult, 48, [[3,5], [4,5], [4,4]]).
cage(mult, 6, [[5,4], [5,5]]).
