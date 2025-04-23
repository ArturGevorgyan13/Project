#include "lesson.h"
//print....................................................................................................................................................................................................
template <typename T>
std::ostream& vhuk::operator<<(std::ostream& out,const FrankList<T>& rhv){

	typename FrankList<T>::const_iterator it(rhv.cbegin());

	for(;it!=rhv.cend();++it){
	
		out<<*it<<" ,";
	
	}

	out<<*it<<" ";

	return out;

}
//base_iterator............................................................................................................................................................................................
template <typename T>
vhuk::FrankList<T>::base_iterator::~base_iterator(){

	

}

template <typename T>
bool vhuk::FrankList<T>::base_iterator::operator==(const base_iterator& rhv) const{

	return (ptr==rhv.ptr);

}

template <typename T>
bool vhuk::FrankList<T>::base_iterator::operator!=(const base_iterator& rhv) const{

	return (ptr!=rhv.ptr);	

}

template <typename T>
vhuk::FrankList<T>::base_iterator::base_iterator(Node* ptr): ptr(ptr) {}
//const_iterator...........................................................................................................................................................................................
template <typename T>
vhuk::FrankList<T>::const_iterator::const_iterator(const base_iterator& rhv): base_iterator(rhv.ptr) {}

template <typename T>
vhuk::FrankList<T>::const_iterator::const_iterator(base_iterator&& rhv){

	this->ptr=rhv.ptr;

	rhv.ptr=0;

}

template <typename T>
const typename vhuk::FrankList<T>::const_iterator& vhuk::FrankList<T>::const_iterator::operator=(const base_iterator& rhv){

	this->ptr=rhv.ptr;

	return *this;	

}

template <typename T>
const typename vhuk::FrankList<T>::const_iterator& vhuk::FrankList<T>::const_iterator::operator=(base_iterator&& rhv){

	this->ptr=rhv.ptr;

	rhv.ptr=nullptr;

	return *this;

}

template <typename T>
typename vhuk::FrankList<T>::const_reference vhuk::FrankList<T>::const_iterator::operator*() const{

	return this->ptr->val;	

}

template <typename T>
typename vhuk::FrankList<T>::const_pointer vhuk::FrankList<T>::const_iterator::operator->() const{

	return &(this->ptr->val);

}

template <typename T>
const typename vhuk::FrankList<T>::const_iterator& vhuk::FrankList<T>::const_iterator::operator++(){

	if(this->ptr->next==nullptr) throw std::out_of_range("Error");

	this->ptr=this->ptr->next;

	return *this;

}

template <typename T>
const typename vhuk::FrankList<T>::const_iterator vhuk::FrankList<T>::const_iterator::operator++(value_type){

	if(this->ptr->next==nullptr) throw std::out_of_range("Error");

	const_iterator tmp=*(this->ptr);

	++*this;

	return tmp;

}

template <typename T>
const typename vhuk::FrankList<T>::const_iterator& vhuk::FrankList<T>::const_iterator::operator--(){

	if(this->ptr->prev==nullptr) throw std::out_of_range("Error");

	this->ptr=this->ptr->prev;

	return *this;	

}

template <typename T>
const typename vhuk::FrankList<T>::const_iterator vhuk::FrankList<T>::const_iterator::operator--(value_type){

	if(this->ptr->prev==nullptr) throw std::out_of_range("Error");

	const_iterator tmp=*(this->ptr);

	--*this;

	return tmp;	

}

template <typename T>
vhuk::FrankList<T>::const_iterator::const_iterator(Node* ptr): base_iterator(ptr) {}
//iterator.................................................................................................................................................................................................
template <typename T>
vhuk::FrankList<T>::iterator::iterator(const base_iterator& rhv): const_iterator(rhv) {}

template <typename T>
vhuk::FrankList<T>::iterator::iterator(base_iterator&& rhv): const_iterator(rhv) {}

template <typename T>
typename vhuk::FrankList<T>::reference vhuk::FrankList<T>::iterator::operator*(){

	return this->ptr->val;	

}

template <typename T>
typename vhuk::FrankList<T>::pointer vhuk::FrankList<T>::iterator::operator->(){

	return &(this->ptr->val);

}

template <typename T>
const typename vhuk::FrankList<T>::iterator& vhuk::FrankList<T>::iterator::operator=(const base_iterator& rhv){

	this->ptr=rhv.ptr;

	return *this;	

}

template <typename T>
const typename vhuk::FrankList<T>::iterator& vhuk::FrankList<T>::iterator::operator=(base_iterator&& rhv){

	this->ptr=rhv.ptr;

	rhv.ptr=nullptr;

	return *this;

}

template <typename T>
vhuk::FrankList<T>::iterator::iterator(Node* ptr): const_iterator(ptr) {}
//const_reverse_iterator...................................................................................................................................................................................
template <typename T>
vhuk::FrankList<T>::const_reverse_iterator::const_reverse_iterator(const base_iterator& rhv): base_iterator(rhv.ptr) {}

template <typename T>
vhuk::FrankList<T>::const_reverse_iterator::const_reverse_iterator(base_iterator&& rhv){

	this->ptr=rhv->ptr;

	rhv->ptr=nullptr;

}

template <typename T>
const typename vhuk::FrankList<T>::const_reverse_iterator& vhuk::FrankList<T>::const_reverse_iterator::operator=(const base_iterator& rhv){

	this->ptr=rhv->ptr;

	return *this;

}

template <typename T>
const typename vhuk::FrankList<T>::const_reverse_iterator& vhuk::FrankList<T>::const_reverse_iterator::operator=(base_iterator&& rhv){

	this->ptr=rhv->ptr;

	rhv->ptr=nullptr;

	return *this;

}

template <typename T>
typename vhuk::FrankList<T>::const_reference vhuk::FrankList<T>::const_reverse_iterator::operator*() const{

	return this->ptr->val;

}

template <typename T>
typename vhuk::FrankList<T>::const_pointer vhuk::FrankList<T>::const_reverse_iterator::operator->() const{

	return &(this->ptr->val);

}

template <typename T>
const typename vhuk::FrankList<T>::const_reverse_iterator& vhuk::FrankList<T>::const_reverse_iterator::operator++(){

	if(this->ptr->prev==nullptr) throw std::out_of_range("Error");

	this->ptr=this->ptr->prev;

	return *this;

}

template <typename T>
const typename vhuk::FrankList<T>::const_reverse_iterator vhuk::FrankList<T>::const_reverse_iterator::operator++(value_type){

	if(this->ptr->prev==nullptr) throw std::out_of_range("Error");

	const_reverse_iterator tmp=*(this->ptr);

	++*this;

	return tmp;

}

template <typename T>
const typename vhuk::FrankList<T>::const_reverse_iterator& vhuk::FrankList<T>::const_reverse_iterator::operator--(){

	if(this->ptr->next==nullptr) throw std::out_of_range("Error");

	this->ptr=this->ptr->next;

	return *this;	

}

template <typename T>
const typename vhuk::FrankList<T>::const_reverse_iterator vhuk::FrankList<T>::const_reverse_iterator::operator--(value_type){

	if(this->ptr->next==nullptr) throw std::out_of_range("Error");

	const_reverse_iterator tmp=*(this->ptr);

	--*this;

	return tmp;	

}

template <typename T>
vhuk::FrankList<T>::const_reverse_iterator::const_reverse_iterator(Node* ptr): base_iterator(ptr) {}
//reverse_iterator.........................................................................................................................................................................................
template <typename T>
vhuk::FrankList<T>::reverse_iterator::reverse_iterator(const base_iterator& rhv): const_reverse_iterator(rhv.ptr) {}

template <typename T>
vhuk::FrankList<T>::reverse_iterator::reverse_iterator(base_iterator&& rhv){

	this->ptr=rhv.ptr;

	rhv.ptr=nullptr;

}

template <typename T>
typename vhuk::FrankList<T>::reference vhuk::FrankList<T>::reverse_iterator::operator*(){

	return this->ptr->val;

}

template <typename T>
typename vhuk::FrankList<T>::pointer vhuk::FrankList<T>::reverse_iterator::operator->(){

	return &(this->ptr->val);

}

template <typename T>
const typename vhuk::FrankList<T>::reverse_iterator& vhuk::FrankList<T>::reverse_iterator::operator=(const base_iterator& rhv){

	this->ptr=rhv->ptr;

	return *this;

}

template <typename T>
const typename vhuk::FrankList<T>::reverse_iterator& vhuk::FrankList<T>::reverse_iterator::operator=(base_iterator&& rhv){

	this->ptr=rhv->ptr;

	rhv->ptr=nullptr;

	return *this;

}

template <typename T>
vhuk::FrankList<T>::reverse_iterator::reverse_iterator(Node* ptr): const_reverse_iterator(ptr) {}
//const_asc_iterator.......................................................................................................................................................................................
template <typename T>
vhuk::FrankList<T>::const_asc_iterator::const_asc_iterator(const base_iterator& rhv): base_iterator(rhv.ptr) {}

template <typename T>
vhuk::FrankList<T>::const_asc_iterator::const_asc_iterator(base_iterator&& rhv){

	this->ptr=rhv.ptr;

	rhv.ptr=0;

}

template <typename T>
const typename vhuk::FrankList<T>::const_asc_iterator& vhuk::FrankList<T>::const_asc_iterator::operator=(const base_iterator& rhv){

	this->ptr=rhv.ptr;

	return *this;	

}

template <typename T>
const typename vhuk::FrankList<T>::const_asc_iterator& vhuk::FrankList<T>::const_asc_iterator::operator=(base_iterator&& rhv){

	this->ptr=rhv.ptr;

	rhv.ptr=nullptr;

	return *this;

}

template <typename T>
typename vhuk::FrankList<T>::const_reference vhuk::FrankList<T>::const_asc_iterator::operator*() const{

	return this->ptr->val;	

}

template <typename T>
typename vhuk::FrankList<T>::const_pointer vhuk::FrankList<T>::const_asc_iterator::operator->() const{

	return &(this->ptr->val);

}

template <typename T>
const typename vhuk::FrankList<T>::const_asc_iterator& vhuk::FrankList<T>::const_asc_iterator::operator++(){

	if(this->ptr->asc==nullptr) throw std::out_of_range("Error");

	this->ptr=this->ptr->asc;

	return *this;

}

template <typename T>
const typename vhuk::FrankList<T>::const_asc_iterator vhuk::FrankList<T>::const_asc_iterator::operator++(value_type){

	if(this->ptr->asc==nullptr) throw std::out_of_range("Error");

	const_asc_iterator tmp=*(this->ptr);

	++*this;

	return tmp;

}

template <typename T>
const typename vhuk::FrankList<T>::const_asc_iterator& vhuk::FrankList<T>::const_asc_iterator::operator--(){

	if(this->ptr->desc==nullptr) throw std::out_of_range("Error");

	this->ptr=this->ptr->desc;

	return *this;	

}

template <typename T>
const typename vhuk::FrankList<T>::const_asc_iterator vhuk::FrankList<T>::const_asc_iterator::operator--(value_type){

	if(this->ptr->desc==nullptr) throw std::out_of_range("Error");

	const_asc_iterator tmp=*(this->ptr);

	--*this;

	return tmp;	

}

template <typename T>
vhuk::FrankList<T>::const_asc_iterator::const_asc_iterator(Node* ptr): base_iterator(ptr) {}
//asc_iterator.............................................................................................................................................................................................
template <typename T>
vhuk::FrankList<T>::asc_iterator::asc_iterator(const base_iterator& rhv): const_asc_iterator(rhv) {}

template <typename T>
vhuk::FrankList<T>::asc_iterator::asc_iterator(base_iterator&& rhv): const_asc_iterator(rhv) {}

template <typename T>
typename vhuk::FrankList<T>::reference vhuk::FrankList<T>::asc_iterator::operator*(){

	return this->ptr->val;	

}

template <typename T>
typename vhuk::FrankList<T>::pointer vhuk::FrankList<T>::asc_iterator::operator->(){

	return &(this->ptr->val);

}

template <typename T>
const typename vhuk::FrankList<T>::asc_iterator& vhuk::FrankList<T>::asc_iterator::operator=(const base_iterator& rhv){

	this->ptr=rhv.ptr;

	return *this;	

}

template <typename T>
const typename vhuk::FrankList<T>::asc_iterator& vhuk::FrankList<T>::asc_iterator::operator=(base_iterator&& rhv){

	this->ptr=rhv.ptr;

	rhv.ptr=nullptr;

	return *this;

}

template <typename T>
vhuk::FrankList<T>::asc_iterator::asc_iterator(Node* ptr): const_asc_iterator(ptr) {}
//const_desc_iterator......................................................................................................................................................................................
template <typename T>
vhuk::FrankList<T>::const_desc_iterator::const_desc_iterator(const base_iterator& rhv): base_iterator(rhv.ptr) {}

template <typename T>
vhuk::FrankList<T>::const_desc_iterator::const_desc_iterator(base_iterator&& rhv){

	this->ptr=rhv->ptr;

	rhv->ptr=nullptr;

}

template <typename T>
const typename vhuk::FrankList<T>::const_desc_iterator& vhuk::FrankList<T>::const_desc_iterator::operator=(const base_iterator& rhv){

	this->ptr=rhv->ptr;

	return *this;

}

template <typename T>
const typename vhuk::FrankList<T>::const_desc_iterator& vhuk::FrankList<T>::const_desc_iterator::operator=(base_iterator&& rhv){

	this->ptr=rhv->ptr;

	rhv->ptr=nullptr;

	return *this;

}

template <typename T>
typename vhuk::FrankList<T>::const_reference vhuk::FrankList<T>::const_desc_iterator::operator*() const{

	return this->ptr->val;

}

template <typename T>
typename vhuk::FrankList<T>::const_pointer vhuk::FrankList<T>::const_desc_iterator::operator->() const{

	return &(this->ptr->val);

}

template <typename T>
const typename vhuk::FrankList<T>::const_desc_iterator& vhuk::FrankList<T>::const_desc_iterator::operator++(){

	if(this->ptr->desc==nullptr) throw std::out_of_range("Error");

	this->ptr=this->ptr->desc;

	return *this;

}

template <typename T>
const typename vhuk::FrankList<T>::const_desc_iterator vhuk::FrankList<T>::const_desc_iterator::operator++(value_type){

	if(this->ptr->desc==nullptr) throw std::out_of_range("Error");

	const_desc_iterator tmp=*(this->ptr);

	++*this;

	return tmp;

}

template <typename T>
const typename vhuk::FrankList<T>::const_desc_iterator& vhuk::FrankList<T>::const_desc_iterator::operator--(){

	if(this->ptr->asc==nullptr) throw std::out_of_range("Error");

	this->ptr=this->ptr->asc;

	return *this;	

}

template <typename T>
const typename vhuk::FrankList<T>::const_desc_iterator vhuk::FrankList<T>::const_desc_iterator::operator--(value_type){

	if(this->ptr->asc==nullptr) throw std::out_of_range("Error");

	const_desc_iterator tmp=*(this->ptr);

	--*this;

	return tmp;	

}

template <typename T>
vhuk::FrankList<T>::const_desc_iterator::const_desc_iterator(Node* ptr): base_iterator(ptr) {}
//desc_iterator............................................................................................................................................................................................
template <typename T>
vhuk::FrankList<T>::desc_iterator::desc_iterator(const base_iterator& rhv): const_desc_iterator(rhv.ptr) {}

template <typename T>
vhuk::FrankList<T>::desc_iterator::desc_iterator(base_iterator&& rhv){

	this->ptr=rhv.ptr;

	rhv.ptr=nullptr;

}

template <typename T>
typename vhuk::FrankList<T>::reference vhuk::FrankList<T>::desc_iterator::operator*(){

	return this->ptr->val;

}

template <typename T>
typename vhuk::FrankList<T>::pointer vhuk::FrankList<T>::desc_iterator::operator->(){

	return &(this->ptr->val);

}

template <typename T>
const typename vhuk::FrankList<T>::desc_iterator& vhuk::FrankList<T>::desc_iterator::operator=(const base_iterator& rhv){

	this->ptr=rhv->ptr;

	return *this;

}

template <typename T>
const typename vhuk::FrankList<T>::desc_iterator& vhuk::FrankList<T>::desc_iterator::operator=(base_iterator&& rhv){

	this->ptr=rhv->ptr;

	rhv->ptr=nullptr;

	return *this;

}

template <typename T>
vhuk::FrankList<T>::desc_iterator::desc_iterator(Node* ptr): const_desc_iterator(ptr) {}
//const_multi_iterator.....................................................................................................................................................................................
template <typename T>
vhuk::FrankList<T>::const_multi_iterator::const_multi_iterator(const base_iterator& rhv): base_iterator(rhv.ptr) {}

template <typename T>
vhuk::FrankList<T>::const_multi_iterator::const_multi_iterator(base_iterator&& rhv){

	this->ptr=rhv->ptr;

	rhv->ptr=nullptr;

}

template <typename T>
const typename vhuk::FrankList<T>::const_multi_iterator& vhuk::FrankList<T>::const_multi_iterator::operator=(const base_iterator& rhv){

	this->ptr=rhv->ptr;

	return *this;

}

template <typename T>
const typename vhuk::FrankList<T>::const_multi_iterator& vhuk::FrankList<T>::const_multi_iterator::operator=(base_iterator&& rhv){

	this->ptr=rhv->ptr;

	rhv->ptr=nullptr;

	return *this;

}

template <typename T>
typename vhuk::FrankList<T>::const_reference vhuk::FrankList<T>::const_multi_iterator::operator*() const{

	return this->ptr->val;

}

template <typename T>
typename vhuk::FrankList<T>::const_pointer vhuk::FrankList<T>::const_multi_iterator::operator->() const{

	return &(this->ptr->val);

}

template <typename T>
const typename vhuk::FrankList<T>::const_multi_iterator& vhuk::FrankList<T>::const_multi_iterator::operator++(){

	if(mode){

		if(this->ptr->next==nullptr){throw std::out_of_range("Error");}
		
		this->ptr=this->ptr->next;

	}

	else {

		if(this->ptr->asc==nullptr){throw std::out_of_range("Error");}
		
		this->ptr=this->ptr->asc;

	}	

	return *this;

}

template <typename T>
const typename vhuk::FrankList<T>::const_multi_iterator vhuk::FrankList<T>::const_multi_iterator::operator++(value_type){

	if(mode){
	
		if(this->ptr->next==nullptr){throw std::out_of_range("Error");}

	}

	else{
	
		if(this->ptr->asc==nullptr){throw std::out_of_range("Error");}
	
	}

	const_multi_iterator tmp=*(this->ptr);

	++*this;

	return tmp;

}

template <typename T>
const typename vhuk::FrankList<T>::const_multi_iterator& vhuk::FrankList<T>::const_multi_iterator::operator--(){

	if(mode){
	
		if(this->ptr->prev==nullptr){throw std::out_of_range("Error");}

		this->ptr=this->ptr->prev;
	
	}

	else{
	
		if(this->ptr->desc==nullptr){throw std::out_of_range("Error");}

		this->ptr=this->ptr->desc;
	
	}

	return *this;

}

template <typename T>
const typename vhuk::FrankList<T>::const_multi_iterator vhuk::FrankList<T>::const_multi_iterator::operator--(value_type){
	
	if(mode){
	
		if(this->ptr->prev==nullptr){throw std::out_of_range("Error");}

	}

	else{
	
		if(this->ptr->desc==nullptr){throw std::out_of_range("Error");}
	
	}

	const_multi_iterator tmp=*(this->ptr);

	++*this;

	return tmp;

}

template <typename T>
void vhuk::FrankList<T>::const_multi_iterator::chmod(){

	mode=!mode;

}

template <typename T>
vhuk::FrankList<T>::const_multi_iterator::const_multi_iterator(Node* ptr): base_iterator(ptr) {}
//multi_iterator...........................................................................................................................................................................................
template <typename T>
vhuk::FrankList<T>::multi_iterator::multi_iterator(const base_iterator& rhv): const_multi_iterator(rhv.ptr) {}

template <typename T>
vhuk::FrankList<T>::multi_iterator::multi_iterator(base_iterator&& rhv){

	this->ptr=rhv.ptr;

	rhv.ptr=nullptr;

}

template <typename T>
typename vhuk::FrankList<T>::reference vhuk::FrankList<T>::multi_iterator::operator*(){

	return this->ptr->val;

}

template <typename T>
typename vhuk::FrankList<T>::pointer vhuk::FrankList<T>::multi_iterator::operator->(){

	return &(this->ptr->val);

}

template <typename T>
const typename vhuk::FrankList<T>::multi_iterator& vhuk::FrankList<T>::multi_iterator::operator=(const base_iterator& rhv){

	this->ptr=rhv->ptr;

	return *this;

}

template <typename T>
const typename vhuk::FrankList<T>::multi_iterator& vhuk::FrankList<T>::multi_iterator::operator=(base_iterator&& rhv){

	this->ptr=rhv->ptr;

	rhv->ptr=nullptr;

	return *this;

}

template <typename T>
vhuk::FrankList<T>::multi_iterator::multi_iterator(Node* ptr): const_multi_iterator(ptr) {}
//const_multi_reverse_iterator.............................................................................................................................................................................
template <typename T>
vhuk::FrankList<T>::const_multi_reverse_iterator::const_multi_reverse_iterator(const base_iterator& rhv): base_iterator(rhv.ptr) {}

template <typename T>
vhuk::FrankList<T>::const_multi_reverse_iterator::const_multi_reverse_iterator(base_iterator&& rhv){

	this->ptr=rhv->ptr;

	rhv->ptr=nullptr;

}

template <typename T>
const typename vhuk::FrankList<T>::const_multi_reverse_iterator& vhuk::FrankList<T>::const_multi_reverse_iterator::operator=(const base_iterator& rhv){

	this->ptr=rhv->ptr;

	return *this;

}

template <typename T>
const typename vhuk::FrankList<T>::const_multi_reverse_iterator& vhuk::FrankList<T>::const_multi_reverse_iterator::operator=(base_iterator&& rhv){

	this->ptr=rhv->ptr;

	rhv->ptr=nullptr;

	return *this;

}

template <typename T>
typename vhuk::FrankList<T>::const_reference vhuk::FrankList<T>::const_multi_reverse_iterator::operator*() const{

	return this->ptr->val;

}

template <typename T>
typename vhuk::FrankList<T>::const_pointer vhuk::FrankList<T>::const_multi_reverse_iterator::operator->() const{

	return &(this->ptr->val);

}

template <typename T>
const typename vhuk::FrankList<T>::const_multi_reverse_iterator& vhuk::FrankList<T>::const_multi_reverse_iterator::operator++(){

	if(mode){

		if(this->ptr->prev==nullptr){throw std::out_of_range("Error");}
		
		this->ptr=this->ptr->prev;

	}

	else {

		if(this->ptr->desc==nullptr){throw std::out_of_range("Error");}
		
		this->ptr=this->ptr->desc;

	}	

	return *this;

}

template <typename T>
const typename vhuk::FrankList<T>::const_multi_reverse_iterator vhuk::FrankList<T>::const_multi_reverse_iterator::operator++(value_type){

	if(mode){
	
		if(this->ptr->prev==nullptr){throw std::out_of_range("Error");}

	}

	else{
	
		if(this->ptr->desc==nullptr){throw std::out_of_range("Error");}
	
	}

	const_multi_reverse_iterator tmp=*(this->ptr);

	++*this;

	return tmp;

}

template <typename T>
const typename vhuk::FrankList<T>::const_multi_reverse_iterator& vhuk::FrankList<T>::const_multi_reverse_iterator::operator--(){

	if(mode){
	
		if(this->ptr->next==nullptr){throw std::out_of_range("Error");}

		this->ptr=this->ptr->next;
	
	}

	else{
	
		if(this->ptr->asc==nullptr){throw std::out_of_range("Error");}

		this->ptr=this->ptr->asc;
	
	}

	return *this;

}

template <typename T>
const typename vhuk::FrankList<T>::const_multi_reverse_iterator vhuk::FrankList<T>::const_multi_reverse_iterator::operator--(value_type){
	
	if(mode){
	
		if(this->ptr->next==nullptr){throw std::out_of_range("Error");}

	}

	else{
	
		if(this->ptr->asc==nullptr){throw std::out_of_range("Error");}
	
	}

	const_multi_reverse_iterator tmp=*(this->ptr);

	++*this;

	return tmp;

}

template <typename T>
void vhuk::FrankList<T>::const_multi_reverse_iterator::chmod(){

	mode=!mode;

}

template <typename T>
vhuk::FrankList<T>::const_multi_reverse_iterator::const_multi_reverse_iterator(Node* ptr): base_iterator(ptr) {}
//multi_reverse_iterator...................................................................................................................................................................................
template <typename T>
vhuk::FrankList<T>::multi_reverse_iterator::multi_reverse_iterator(const base_iterator& rhv): const_multi_reverse_iterator(rhv.ptr) {}

template <typename T>
vhuk::FrankList<T>::multi_reverse_iterator::multi_reverse_iterator(base_iterator&& rhv){

	this->ptr=rhv.ptr;

	rhv.ptr=nullptr;

}

template <typename T>
typename vhuk::FrankList<T>::reference vhuk::FrankList<T>::multi_reverse_iterator::operator*(){

	return this->ptr->val;

}

template <typename T>
typename vhuk::FrankList<T>::pointer vhuk::FrankList<T>::multi_reverse_iterator::operator->(){

	return &(this->ptr->val);

}

template <typename T>
const typename vhuk::FrankList<T>::multi_reverse_iterator& vhuk::FrankList<T>::multi_reverse_iterator::operator=(const base_iterator& rhv){

	this->ptr=rhv->ptr;

	return *this;

}

template <typename T>
const typename vhuk::FrankList<T>::multi_reverse_iterator& vhuk::FrankList<T>::multi_reverse_iterator::operator=(base_iterator&& rhv){

	this->ptr=rhv->ptr;

	rhv->ptr=nullptr;

	return *this;

}

template <typename T>
vhuk::FrankList<T>::multi_reverse_iterator::multi_reverse_iterator(Node* ptr): const_multi_reverse_iterator(ptr) {}
//Node.....................................................................................................................................................................................................
template <typename T>
vhuk::FrankList<T>::Node::Node(): val(T()),next(nullptr),prev(nullptr),asc(nullptr),desc(nullptr) {}

template <typename T>
vhuk::FrankList<T>::Node::Node(T val): val(val),next(nullptr),prev(nullptr),asc(nullptr),desc(nullptr) {}
//FrankList................................................................................................................................................................................................
template <typename T>
vhuk::FrankList<T>::FrankList(): head(nullptr),tail(nullptr),ahead(nullptr),atail(nullptr) {}

template <typename T>
vhuk::FrankList<T>::FrankList(size_type size): FrankList() {

	Node* newnode=new Node();

	head=newnode;

	ahead=newnode;

	Node* current=head;

	for(size_t i=0;i<size-1;i++){

		current->next=new Node();

		Node* prevcurrent=current;

		current=current->next;

		current->prev=prevcurrent;

		prevcurrent->asc=current;

		current->desc=prevcurrent;
	
	}

	tail=current;

	atail=current;

}

template <typename T>
vhuk::FrankList<T>::FrankList(size_type size,const_reference init): FrankList() {

	Node* newnode=new Node(init);

	head=newnode;

	ahead=newnode;

	Node* current=head;

	for(size_t i=0;i<size-1;i++){

		current->next=new Node(init);

		Node* prevcurrent=current;

		current=current->next;

		current->prev=prevcurrent;

		prevcurrent->asc=current;

		current->desc=prevcurrent;
	
	}

	tail=current;

	atail=current;

}

template <typename T>
vhuk::FrankList<T>::FrankList(const FrankList<value_type>& rhv): FrankList(rhv.size()) {

	iterator it1=this->cbegin();

	const_iterator it2=rhv.cbegin();

	while(it2!=rhv.cend()){
	
		*it1=*it2;

		++it2;

		++it1;	
	
	}

	*it1=*it2;

	it1=this->begin();

	while(it1!=cend()){
	
		put_in_sorted_order(it1.ptr);
	
		++it1;

	}

	put_in_sorted_order(it1.ptr);

}

template <typename T>
vhuk::FrankList<T>::FrankList(FrankList<value_type>&& rhv): FrankList() {

	this->head=rhv.head;

	this->tail=rhv.tail;

	this->ahead=rhv.ahead;

	this->atail=rhv.atail;

	rhv.head=nullptr;

	rhv.tail=nullptr;

	rhv.ahead=nullptr;

	rhv.atail=nullptr;

}

template <typename T>
vhuk::FrankList<T>::FrankList(std::initializer_list<value_type> init): FrankList() {

	for(typename std::initializer_list<value_type>::iterator it=init.begin();it!=init.end();++it){
	
		push_back(*it);
	
	}

}

template <typename T>
template <typename input_iterator>
vhuk::FrankList<T>::FrankList(input_iterator f,input_iterator l): FrankList() {

	for(input_iterator it=f;it!=l;++it){
	
		push_back(*it);
	
	}

}

template <typename T>
vhuk::FrankList<T>::~FrankList(){

	clear();	

}
//operators................................................................................................................................................................................................
template <typename T>
const typename vhuk::FrankList<T>::FrankList<typename vhuk::FrankList<T>::value_type>& vhuk::FrankList<T>::operator=(const FrankList<typename vhuk::FrankList<T>::value_type>& rhv){

        iterator it1=this->cbegin();

        const_iterator it2=rhv.cbegin();

        while(it2!=rhv.cend()){

                *it1=*it2;

                ++it2;

                ++it1;

        }

        *it1=*it2;

	it1=this->begin();

	while(it1!=rhv.cend()){
	
		put_in_sorted_order(it1.ptr);

		++it1;
	
	}

	put_in_sorted_order(it1.ptr);

	return *this;

}

template <typename T>
const typename vhuk::FrankList<T>::FrankList<typename vhuk::FrankList<T>::value_type>& vhuk::FrankList<T>::operator=(FrankList<typename vhuk::FrankList<T>::value_type>&& rhv){

	this->clear();

	this->head=rhv.head;

        this->tail=rhv.tail;

        this->ahead=rhv.ahead;

        this->atail=rhv.atail;

        rhv.head=nullptr;

        rhv.tail=nullptr;

        rhv.ahead=nullptr;

        rhv.atail=nullptr;

	return *this;


}

template <typename T>
const typename vhuk::FrankList<T>::FrankList<typename vhuk::FrankList<T>::value_type>& vhuk::FrankList<T>::operator=(std::initializer_list<value_type> init){

        for(typename std::initializer_list<value_type>::iterator it=init.begin();it!=init.end();++it){

                push_back(*it);

        }

	return *this;	

}

template <typename T>
bool vhuk::FrankList<T>::operator==(const FrankList<typename vhuk::FrankList<T>::value_type>& rhv) const{

	if (this->size()!=rhv.size()){

        	return false;

    	}

	auto it1=this->begin();

    	auto it2=rhv.begin();

    	while(it1!=this->end() && it2!=rhv.end()){

        if (*it1!=*it2){

            return false;

        }

        ++it1;

        ++it2;
	
	}

    	return (it1==this->end() && it2==rhv.end());

}

template <typename T>
bool vhuk::FrankList<T>::operator!=(const FrankList<typename vhuk::FrankList<T>::value_type>& rhv) const{

	return !(*this==rhv);

}

template <typename T>
bool vhuk::FrankList<T>::operator<(const FrankList<typename vhuk::FrankList<T>::value_type>& rhv) const{

	auto it1=this->begin();

    	auto it2=rhv.begin();

    	while (it1!=this->end() && it2!=rhv.end()){

        if(*it1<*it2){

        	return true;

        }else if(*it2<*it1){

            	return false;

        }

        ++it1;

        ++it2;

    	}

	return (it1==this->end() && it2!=rhv.end());

}

template <typename T>
bool vhuk::FrankList<T>::operator<=(const FrankList<typename vhuk::FrankList<T>::value_type>& rhv) const{

	return (*this<rhv) || (*this==rhv);

}

template <typename T>
bool vhuk::FrankList<T>::operator>(const FrankList<typename vhuk::FrankList<T>::value_type>& rhv) const{

	return rhv<*this;

}

template <typename T>
bool vhuk::FrankList<T>::operator>=(const FrankList<typename vhuk::FrankList<T>::value_type>& rhv) const{

	return (*this>rhv) || (*this==rhv);

}
//const_iterator functions.................................................................................................................................................................................
template <typename T>
typename vhuk::FrankList<T>::const_iterator vhuk::FrankList<T>::cbegin() const{

	return const_iterator(head);	

}

template <typename T>
typename vhuk::FrankList<T>::const_iterator vhuk::FrankList<T>::cend() const{

	return const_iterator(tail);	

}

template <typename T>
typename vhuk::FrankList<T>::const_reverse_iterator vhuk::FrankList<T>::crbegin() const{

	return const_reverse_iterator(tail);	

}

template <typename T>
typename vhuk::FrankList<T>::const_reverse_iterator vhuk::FrankList<T>::crend() const{

	return const_reverse_iterator(head);	

}

template <typename T>
typename vhuk::FrankList<T>::const_asc_iterator vhuk::FrankList<T>::cabegin() const{

	return const_asc_iterator(ahead);	

}

template <typename T>
typename vhuk::FrankList<T>::const_asc_iterator vhuk::FrankList<T>::caend() const{

	return const_asc_iterator(atail);	

}

template <typename T>
typename vhuk::FrankList<T>::const_desc_iterator vhuk::FrankList<T>::cdbegin() const{

	return const_desc_iterator(atail);	

}

template <typename T>
typename vhuk::FrankList<T>::const_desc_iterator vhuk::FrankList<T>::cdend() const{

	return const_desc_iterator(ahead);	

}

template <typename T>
typename vhuk::FrankList<T>::const_multi_iterator vhuk::FrankList<T>::cmbegin() const{

	return const_multi_iterator(head);	

}

template <typename T>
typename vhuk::FrankList<T>::const_multi_iterator vhuk::FrankList<T>::cmend() const{

	return const_multi_iterator(tail);	

}

template <typename T>
typename vhuk::FrankList<T>::const_multi_iterator vhuk::FrankList<T>::cmabegin() const{

	return const_multi_iterator(ahead);	

}

template <typename T>
typename vhuk::FrankList<T>::const_multi_iterator vhuk::FrankList<T>::cmaend() const{

	return const_multi_iterator(atail);	

}

template <typename T>
typename vhuk::FrankList<T>::const_multi_reverse_iterator vhuk::FrankList<T>::cmrbegin() const{

	return const_multi_reverse_iterator(tail);	

}

template <typename T>
typename vhuk::FrankList<T>::const_multi_reverse_iterator vhuk::FrankList<T>::cmrend() const{

	return const_multi_reverse_iterator(head);	

}

template <typename T>
typename vhuk::FrankList<T>::const_multi_reverse_iterator vhuk::FrankList<T>::cmrdbegin() const{

	return const_multi_reverse_iterator(atail);	

}

template <typename T>
typename vhuk::FrankList<T>::const_multi_reverse_iterator vhuk::FrankList<T>::cmrdend() const{

	return const_multi_reverse_iterator(ahead);	

}
//iterator functions........................................................................................................................................................................................
template <typename T>
typename vhuk::FrankList<T>::iterator vhuk::FrankList<T>::begin(){

	return iterator(head);	

}

template <typename T>
typename vhuk::FrankList<T>::iterator vhuk::FrankList<T>::end(){

	return iterator(tail);	

}

template <typename T>
typename vhuk::FrankList<T>::reverse_iterator vhuk::FrankList<T>::rbegin(){

	return reverse_iterator(tail);	

}

template <typename T>
typename vhuk::FrankList<T>::reverse_iterator vhuk::FrankList<T>::rend(){

	return reverse_iterator(head);	

}

template <typename T>
typename vhuk::FrankList<T>::asc_iterator vhuk::FrankList<T>::abegin(){

	return asc_iterator(ahead);	

}

template <typename T>
typename vhuk::FrankList<T>::asc_iterator vhuk::FrankList<T>::aend(){

	return asc_iterator(atail);	

}

template <typename T>
typename vhuk::FrankList<T>::desc_iterator vhuk::FrankList<T>::dbegin(){

	return desc_iterator(atail);	

}

template <typename T>
typename vhuk::FrankList<T>::desc_iterator vhuk::FrankList<T>::dend(){

	return desc_iterator(ahead);	

}

template <typename T>
typename vhuk::FrankList<T>::multi_iterator vhuk::FrankList<T>::mbegin(){

	return multi_iterator(head);	

}

template <typename T>
typename vhuk::FrankList<T>::multi_iterator vhuk::FrankList<T>::mend(){

	return multi_iterator(tail);	

}

template <typename T>
typename vhuk::FrankList<T>::multi_iterator vhuk::FrankList<T>::mabegin(){

	return multi_iterator(ahead);	

}

template <typename T>
typename vhuk::FrankList<T>::multi_iterator vhuk::FrankList<T>::maend(){

	return multi_iterator(atail);	

}

template <typename T>
typename vhuk::FrankList<T>::multi_reverse_iterator vhuk::FrankList<T>::mrbegin(){

	return multi_reverse_iterator(tail);	

}

template <typename T>
typename vhuk::FrankList<T>::multi_reverse_iterator vhuk::FrankList<T>::mrend(){

	return multi_reverse_iterator(head);	

}

template <typename T>
typename vhuk::FrankList<T>::multi_reverse_iterator vhuk::FrankList<T>::mrdbegin(){

	return multi_reverse_iterator(atail);	

}

template <typename T>
typename vhuk::FrankList<T>::multi_reverse_iterator vhuk::FrankList<T>::mrdend(){

	return multi_reverse_iterator(ahead);	

}
//implementation...........................................................................................................................................................................................
template <typename T>
void vhuk::FrankList<T>::swap(FrankList<value_type>& rhv){

	Node* tmphead=head;

	head=rhv.head;

	rhv.head=tmphead;

	Node* tmptail=tail;

	tail=rhv.tail;

	rhv.tail=tmptail;

	Node*  tmpahead=ahead;

	ahead=rhv.ahead;

	rhv.ahead=tmphead;

	Node* tmpatail=atail;

	atail=rhv.atail;

	rhv.atail=tmpatail;	

}

template <typename T>
typename vhuk::FrankList<T>::size_type vhuk::FrankList<T>::size() const{

	const_iterator it(this->cbegin());

	vhuk::FrankList<T>::size_type size=1;

	while(it!=this->cend()){
	
		++size;

		++it;
	
	}

	return size;

}

template <typename T>
bool vhuk::FrankList<T>::empty() const{

	return !head;

}

template <typename T>
void vhuk::FrankList<T>::resize(size_type s,const_reference init){

	if(s=size()) return;

	if(s>size()){
	
		size_t tmp=s-size();

		for(size_t i=0;i<tmp;i++){
		
			push_back(init);
		
		}		
	
	}	

	else{
	
		size_t tmp=size()-s;

		for(size_t i=0;i<tmp;i++){
		
			pop_back();
		
		}
	
	}

}

template <typename T>
void vhuk::FrankList<T>::clear() noexcept{

	iterator it(this->begin());

	while(it!=this->end()){
	
		Node* tmp=it.ptr;

		++it;

		delete tmp;
	
	}	

	delete it.ptr;

}

template <typename T>
void vhuk::FrankList<T>::push_front(const_reference elem){

	Node* newnode=new Node(elem);

	newnode->next=head;

	head->prev=newnode;

	head=newnode;

	put_in_sorted_order(head);	

}

template <typename T>
void vhuk::FrankList<T>::pop_front(){

	Node* atmp=head->asc;

	Node* dtmp=head->desc;

	atmp->desc=dtmp;

	dtmp->asc=atmp;

	head=head->next;
	
	delete head->prev;

	head->prev=nullptr;	

}

template <typename T>
void vhuk::FrankList<T>::push_back(const_reference elem){

	Node* newnode=new Node(elem);

	tail->next=newnode;

	newnode->prev=tail;

	tail=newnode;

	put_in_sorted_order(tail);

}

template <typename T>
void vhuk::FrankList<T>::pop_back(){

	Node* atmp=tail->asc;

	Node* dtmp=tail->desc;

	atmp->desc=dtmp;

	dtmp->asc=atmp;

	tail=tail->prev;

	delete tail->next;

	tail->next=nullptr;

}

template <typename T>
typename vhuk::FrankList<T>::const_reference vhuk::FrankList<T>::front() const{

	return head->val;

}

template <typename T>
typename vhuk::FrankList<T>::reference vhuk::FrankList<T>::front(){

	return head->val;

}

template <typename T>
typename vhuk::FrankList<T>::const_reference vhuk::FrankList<T>::back() const{

	return tail->val;

}

template <typename T>
typename vhuk::FrankList<T>::reference vhuk::FrankList<T>::back(){

	return tail->val;

}

template <typename T>
typename vhuk::FrankList<T>::const_reference vhuk::FrankList<T>::min() const{

	return ahead->val;

}

template <typename T>
typename vhuk::FrankList<T>::reference vhuk::FrankList<T>::min(){

	return ahead->val;

}

template <typename T>
typename vhuk::FrankList<T>::const_reference vhuk::FrankList<T>::max() const{

	return atail->val;

}

template <typename T>
typename vhuk::FrankList<T>::reference vhuk::FrankList<T>::max(){

	return atail->val;

}
//interesting..............................................................................................................................................................................................
template <typename T>
template <typename iter>
iter vhuk::FrankList<T>::insert(iter pos,size_type size,const_reference val){

	iter postmp=pos;

	for(size_t i=0;i<size;i++){
	
		postmp=insert_def(postmp,val);
	
	}

	return postmp;

}

template <typename T>
template <typename iter>
iter vhuk::FrankList<T>::insert(iter pos,std::initializer_list<value_type> init){

	iter postmp=pos;

	for(typename std::initializer_list<value_type>::iterator it=init.begin();it!=init.end();++it){
	
		postmp=insert_def(postmp,*it);
	
	}

	return postmp;

}

template <typename T>
template <typename iter,typename input_iterator>
iter vhuk::FrankList<T>::insert(iter pos,input_iterator f,input_iterator l){

	iter postmp=pos;

	for(input_iterator it=f;it!=l;++it){
	
		postmp=inser_def(postmp,*it);
	
	}

	return postmp;

}

template <typename T>
template <typename iter>
iter vhuk::FrankList<T>::erase(iter pos){

	iter it=++pos;

	remove(*pos);

	return it;

}

template <typename T>
template <typename iter>
iter vhuk::FrankList<T>::erase(iter f,iter l){

	iter tmp=++f;

	for(iter it=f;it!=l;++it){
	
		remove(*it);

		++tmp;
	
	}

	return tmp;

}

template <typename T>
typename vhuk::FrankList<T>::size_type vhuk::FrankList<T>::remove(const_reference val){

	size_t count=this->size();

	while(val==this->front()){
	
		pop_front();

		count--;
	
	}

	while(val==this->back()){
	
		pop_back();

		count--;
	
	}

	iterator it(this->begin());

	while(it!=end()){
	
		if(*it==val){

			iterator ittmp=it;
		
			Node* tmp1=it.ptr->next;

			Node* tmp2=it.ptr->prev;

			tmp1->prev=tmp2;

			tmp2->next=tmp1;

			tmp1=it.ptr->asc;

			tmp2=it.ptr->desc;

			tmp1->desc=tmp2;

			tmp2->asc=tmp1;

			++it;

			delete ittmp.ptr;

			count--;
		
		}

		else{

			++it;
		
		}
	
	}

	return count;

}

template <typename T>
template <typename unary_predicate>
typename vhuk::FrankList<T>::size_type vhuk::FrankList<T>::remove_if(unary_predicate func){

	size_t count=this->size();

	while(func(this->front())){
	
		pop_front();

		count--;
	
	}

	while(func(this->back())){
	
		pop_back();

		count--;
	
	}

	iterator it(this->begin());

	while(it!=end()){
	
		if(func(*it)){

			iterator ittmp=it;
		
			Node* tmp1=it.ptr->next;

			Node* tmp2=it.ptr->prev;

			tmp1->prev=tmp2;

			tmp2->next=tmp1;

			tmp1=it.ptr->asc;

			tmp2=it.ptr->desc;

			tmp1->desc=tmp2;

			tmp2->asc=tmp1;

			++it;

			delete ittmp.ptr;

			count--;
		
		}

		else{

			++it;
		
		}
	
	}

	return count;

}

template <typename T>
void vhuk::FrankList<T>::reverse(){

	Node* current=head;

	Node* tmp=nullptr;

	while(!current){

		tmp=current->prev;
	
		current->prev=current->next;

		current->next=tmp;

		current=current->prev;
	
	}

	tmp=head;

	head=tail;

	tail=tmp;

}

template <typename T>
void vhuk::FrankList<T>::sort(bool reversed){

	if(!reversed){
	
		asc_iterator it(this->abegin());

		while(it!=this->aend()){
		
			it.ptr->next=it.ptr->asc;

			it.ptr->prev=it.ptr->desc;

			++it;
		
		}

		it.ptr->next=it.ptr->asc;

		it.ptr->prev=it.ptr->desc;

		head=ahead;

		tail=atail;		
	
	}

	else{
	
		desc_iterator it(this->dbegin());

		while(it!=this->dend()){
		
			it.ptr->next=it.ptr->desc;

			it.ptr->prev=it.ptr->asc;
		
		}

		it.ptr->next=it.ptr->desc;

		it.ptr->prev=it.ptr->asc;

		head=atail;

		tail=ahead;
	
	}

}

template <typename T>
typename vhuk::FrankList<T>::iterator vhuk::FrankList<T>::find(const_reference elem){

	iterator it(this->begin());

	for(;it!=end();++it){
	
		if(*it==elem){
		
			return it;
		
		}
	
	}

	if(*it==elem){
	
		return it;
	
	}

	else throw std::out_of_range("Error");

}

template <typename T>
typename vhuk::FrankList<T>::iterator vhuk::FrankList<T>::rfind(const_reference elem){

	iterator it(this->end());

	for(;it!=begin();--it){
	
		if(*it==elem){
		
			return it;
		
		}
	
	}

	if(*it==elem){
	
		return it;
	
	}

	else throw std::out_of_range("Error");

}

template <typename T>
template <typename unary_predicate>
void vhuk::FrankList<T>::traverse(unary_predicate func,bool sorted,bool reversed){

	if(sorted && reversed){
	
		desc_iterator it(this->dbegin());

		while(it!=dend()){
		
			func(*it);
		
			++it;

		}

		func(*it);
	
	}

	else if(!sorted && reversed){
	
		reverse_iterator it(this->rbegin());

		while(it!=rend()){
		
			func(*it);

			++it;
		
		}

		func(*it);
	
	}

	else if(sorted && !reversed){
	
		asc_iterator it(this->abegin());

		while(it!=aend()){
		
			func(*it);

			++it;
		
		}

		func(*it);
	
	}

	else{
	
		iterator it(this->begin());

		while(it!=end()){
		
			func(*it);

			++it;
		
		}

		func(*it);
	
	}

}

template <typename T>
void vhuk::FrankList<T>::print(bool sorted,bool reversed){

	if(sorted && reversed){
	
		desc_iterator it(this->dbegin());

		while(it!=dend()){
		
			std::cout<<*it<<" ";
		
			++it;

		}

		std::cout<<*it<<" ";
	
	}

	else if(!sorted && reversed){
	
		reverse_iterator it(this->rbegin());

		while(it!=rend()){
		
			std::cout<<*it<<" ";

			++it;
		
		}

		std::cout<<*it<<" ";
	
	}

	else if(sorted && !reversed){
	
		asc_iterator it(this->abegin());

		while(it!=aend()){
		
			std::cout<<*it<<" ";

			++it;
		
		}

		std::cout<<*it<<" ";
	
	}

	else{
	
		iterator it(this->begin());

		while(it!=end()){
		
			std::cout<<*it<<" ";

			++it;
		
		}

		std::cout<<*it<<" ";
	
	}

}

template <typename T>
void vhuk::FrankList<T>::put_in_sorted_order(Node* ptr){

	asc_iterator it(abegin());

	if(ptr->val<this->min()){
	
		ptr->asc=ahead;

		ahead->desc=ptr;

		ahead=ptr;

		ahead->desc=nullptr;

		return;
	
	}

	if(ptr->val>=this->max()){
	
		ptr->desc=atail;

		atail->asc=ptr;

		atail=ptr;

		atail->asc=nullptr;
	
		return;

	}

	while(it!=this->aend()){
	
		if(ptr->val>=*it && ptr->val<=it.ptr->asc->val){

			Node* tmp=it.ptr->asc;

			it.ptr->asc=ptr;

			ptr->desc=it.ptr;

			tmp->desc=ptr;

			ptr->asc=tmp;
		
			return;

		}

		++it;
	
	}

}

template <typename T>
void vhuk::FrankList<T>::organize_left(Node* ptr){

	if(ptr==nullptr || ptr->prev==nullptr || ptr->val>=ptr->prev->val) return;

    	Node* prevNode=ptr->prev;

    	Node* nextNode=ptr->next;

    	if(nextNode!=nullptr){

        	nextNode->prev=prevNode;

    	}
	
	else{

        	atail=prevNode;
	
	}

    	prevNode->next=nextNode;

    	ptr->next=prevNode;

    	ptr->prev=prevNode->prev;

    	if(prevNode->prev!=nullptr){
        
		prevNode->prev->next=ptr;

   	} 	
	
	else{

        	ahead=ptr;

    	}

    	prevNode->prev=ptr;

}

template <typename T>
void vhuk::FrankList<T>::organize_right(Node* ptr){

	if(ptr==nullptr || ptr->next==nullptr || ptr->val<=ptr->next->val) return;

    	Node* prevNode=ptr->prev;

    	Node* nextNode=ptr->next;

    	if(prevNode!=nullptr) {
        
		prevNode->next=nextNode;

    	}
	
	else{

        	ahead=nextNode;
    	
	}

    	nextNode->prev=prevNode;

    	ptr->prev=nextNode;
	
    	ptr->next=nextNode->next;

    	if(nextNode->next!=nullptr){

        	nextNode->next->prev=ptr;

    	}
	
	else {
        
		atail=ptr;

    	}

    	nextNode->next=ptr;

}

template <typename T>
template <typename iter>
iter vhuk::FrankList<T>::insert_def(iter pos,const_reference val){

	if(pos.ptr==tail){
			
		push_back(val);	

		iter it(tail);	

		return it;	

	}

	Node* newnode=new Node(val);

	Node* tmp=pos.ptr->next;

	pos.ptr->next=newnode;

	newnode->prev=pos.ptr;

	newnode->next=tmp;

	tmp->prev=newnode;

	put_in_sorted_order(newnode);

	iter it(newnode);

	return it;

}

template <typename T>
template <typename iter>
iter vhuk::FrankList<T>::insert_rev(iter pos,const_reference val){

	if(pos.ptr==head){
			
		push_front(val);	

		iter it(head);	

		return it;	

	}

	Node* newnode=new Node(val);

	Node* tmp=pos.ptr->prev;

	pos.ptr->prev=newnode;

	newnode->next=pos.ptr;

	newnode->prev=tmp;

	tmp->next=newnode;

	put_in_sorted_order(newnode);

	iter it(newnode);

	return it;

}

int main()

{

	return 0;

}
